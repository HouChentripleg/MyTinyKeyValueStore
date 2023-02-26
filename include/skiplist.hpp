#pragma once

#include "listnode.hpp"
#include <mutex>
#include <random>
#include <string>
#include <cstring>
#include <fstream>

#define STORE_FILE "../store/dumpfile.txt"
std::mutex mtx, mutex;

template<typename K, typename V>
class SkipList {
private:
    int maxLevel_;
    int curLevel_;
    ListNode<K, V>* header_;    // head node of skiplist
    std::ofstream writer_;
    std::ifstream reader_;
    int elementCnt_;
public:
    SkipList(int);
    SkipList(const SkipList&) = delete;
    SkipList& operator=(const SkipList&) = delete;
    SkipList& operator=(SkipList&&) = delete;
    ~SkipList();

    int randomLevel();
    ListNode<K, V>* newNode(K, V, int);
    bool searchElement(K);
    int insertElement(K, V);
    void deleteElement(K);
    int updateElement(K, V);
    void displaySkiplist();
    void clearSkiplist();
    void dumpFile(); // 数据落盘
    void loadFile(); // 数据加载
    bool getKeyValueFromFile(const std::string&, std::string*, std::string*);
    bool isValidString(const std::string&);
    int size() {
        return elementCnt_;
    }
};

template<typename K, typename V>
SkipList<K, V>::SkipList(int maxLevel) : maxLevel_(maxLevel), curLevel_(0), elementCnt_(0) {
    K k = K();
    V v = V();
    header_ = newNode(k, v, maxLevel);
}

template<typename K, typename V>
SkipList<K, V>::~SkipList() {
    // 关闭文件
    if(writer_.is_open()) writer_.close();
    if(reader_.is_open()) reader_.close();

    // 删除链表节点
    ListNode<K, V>* curNode = header_;
    ListNode<K, V>* delNode;
    while(curNode != nullptr) {
        delNode = curNode;
        curNode = curNode->forward_[0];
        delete delNode;
    }
}

template<typename K, typename V>
int SkipList<K, V>::randomLevel() {
    int level = 1;
    while(rand() % 2) {
        ++level;
    }
    level = level < maxLevel_ ? level : maxLevel_;
    return level;
}

template<typename K, typename V>
ListNode<K, V>* SkipList<K, V>::newNode(K k, V v, int level) {
    ListNode<K, V>* node = new ListNode<K, V>(k, v, level);
    return node;
}

template<typename K, typename V>
bool SkipList<K, V>::searchElement(K key) {
    std::cout << "searching element...\n";
    ListNode<K, V>* curNode = header_;

    for(int i = curLevel_; i >= 0; i--) {
        while(curNode->forward_[i] != nullptr && curNode->forward_[i]->getKey() < key) {
            curNode = curNode->forward_[i];
        }
    }
    curNode = curNode->forward_[0];
    if(curNode != nullptr && curNode->getKey() == key) {
        std::cout << "Found Element! key: " << key << ", value: " << curNode->getValue() << std::endl;
        return true;
    }
    std::cout << "key: "<< key << ", 404 Not Found!\n";
    return false;
}

template<typename K, typename V>
int SkipList<K, V>::insertElement(K key, V value) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "inserting element...\n";
    ListNode<K, V>* curNode = header_;

    ListNode<K, V>* update[maxLevel_ + 1];  // 新增元素的指针数组
    memset(update, 0, sizeof(update));

    for(int i = curLevel_; i >= 0; i--) {
        while(curNode->forward_[i] != nullptr && curNode->forward_[i]->getKey() < key) {
            curNode = curNode->forward_[i];
        }
        update[i] = curNode;    // 将新增节点的前序节点存储在对应的索引层
    }
    curNode = curNode->forward_[0];

    if(curNode != nullptr && curNode->getKey() == key) {
        std::cout << "key: " << curNode->getKey() << " is already exist\n";
        return 1;
    }

    if(curNode == nullptr || curNode->getKey() > key) {
        int randomL = randomLevel();    // 随机获取待插入的索引层

        if(randomL > curLevel_) {
            for(int i = curLevel_ + 1; i < randomL + 1; i++) {
                update[i] = header_;    // 存储头节点
            }
            curLevel_ = randomL;
        }

        ListNode<K, V>* insertedNode = newNode(key, value, randomL);
        // 在合适的位置插入新节点insertedNode
        for(int i = 0; i <= randomL; i++) {
            insertedNode->forward_[i] =update[i]->forward_[i];
            update[i]->forward_[i] = insertedNode;
        }
        // std::cout << "insert successfully! key: " << key << ", value: " << value << std::endl;
        ++elementCnt_;
    }
    return 0;
}

template<typename K, typename V>
void SkipList<K, V>::deleteElement(K key) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "deleting element...\n";

    ListNode<K, V>* curNode = header_;
    ListNode<K, V>* update[maxLevel_ + 1];
    memset(update, 0, sizeof(update));

    for(int i = curLevel_; i >= 0; i--) {
        while(curNode->forward_[i] != nullptr && curNode->forward_[i]->getKey() < key) {
            curNode = curNode->forward_[i];
        }
        update[i] = curNode; // update中保存待删节点本身or待删节点所在区间的起点节点
    }
    curNode = curNode->forward_[0];

    if(curNode != nullptr && curNode->getKey() == key) {
        // 从原始链表开始删除指定元素
        for(int i = 0; i <= curLevel_; i++) {
            if(update[i]->forward_[i] != curNode) break; // 若第i层索引中，next node并非待删节点，退出循环
            update[i]->forward_[i] = curNode->forward_[i];
        }

        // 移除没有元素的索引层
        while(curLevel_ > 0 && header_->forward_[curLevel_] == 0) curLevel_--;
        
        std::cout << "key: " << key << " deleted successfully!\n";
        elementCnt_--;
    }
    return;
}

template<typename K, typename V>
int SkipList<K, V>::updateElement(K key, V value) {
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "updating element...\n";

    ListNode<K, V>* curNode = header_;
    ListNode<K, V>* update[maxLevel_ + 1];
    memset(update, 0, sizeof(update));

    for(int i = curLevel_; i >= 0; i--) {
        while(curNode->forward_[i] != nullptr && curNode->forward_[i]->getKey() < key) {
            curNode = curNode->forward_[i];
        }
        update[i] = curNode;
    }
    curNode = curNode->forward_[0];

    if(curNode != nullptr && curNode->getKey() == key) {
        // 更新元素已存在
        std::cout << "key: " << key <<" already exists\n";
        std::cout << "value: " << curNode->getValue() << " --> ";
        std::cout << curNode->setValue(value) << std::endl;
        return 1;
    } else {
        // 更新元素不存在
        std::cout << "key: " << key <<" does not exist, insert new node\n";
        SkipList<K, V>::insertElement(key, value);
        return 0;
    }
}

template<typename K, typename V>
void SkipList<K, V>::displaySkiplist() {
    std::cout << "-------SkipList-------\n";
    for(int i = 0; i <= curLevel_; i++) {
        ListNode<K, V>* node = header_->forward_[i];
        std::cout << "Level " << i << ": ";
        while(node != nullptr) {
            std::cout << node->getKey() << ":" << node->getValue() << "; ";
            node = node->forward_[i];
        }
        std::cout << std::endl;
    }
}

template<typename K, typename V>
void SkipList<K, V>::clearSkiplist() {
    std::cout << "clearing skiplist...\n";
    ListNode<K, V>* curNode = header_->forward_[0];

    // 删除数据节点
    while(curNode != nullptr) {
        ListNode<K, V>* tmp = curNode;
        curNode = curNode->forward_[0];
        delete tmp;
    }

    // 初始化头节点
    for(int i = 0; i < maxLevel_; i++) {
        header_->forward_[i] = nullptr;
    }
    this->curLevel_ = 0;
    this->elementCnt_ = 0;
    return;
}

template<typename K, typename V>
void SkipList<K, V>::dumpFile() {
    std::cout << "dumping data from memory to file...\n";
    writer_.open(STORE_FILE);
    ListNode<K, V>* node = header_->forward_[0];

    while(node != nullptr) {
        writer_ << node->getKey() << ':' << node->getValue() << std::endl;
        node = node->forward_[0];
    }

    writer_.flush();
    writer_.close();
    std::cout << "dump file successfully!\n";
    return;
}

template<typename K, typename V>
void SkipList<K, V>::loadFile() {
    reader_.open(STORE_FILE);
    std::cout << "loading file to memory...\n";
    std::string line;
    std::string* key = new std::string();
    std::string* value = new std::string();
    while(getline(reader_, line)) {
        getKeyValueFromFile(line, key, value);
        if(key->empty() || value->empty()) continue;
        insertElement(*key, *value);
        std::cout << "key: " << *key << " value: " << *value << std::endl;
    }
    reader_.close();
    delete key;
    delete value;
}

template<typename K, typename V>
bool SkipList<K, V>::getKeyValueFromFile(const std::string& str, std::string* key, std::string* value) {
    if(!isValidString(str)) {
        std::cout << "invalid input string\n";
        return false;
    }
    *key = str.substr(0, str.find(':'));
    *value = str.substr(str.find(':') + 1, str.length());
    return true;
}

template<typename K, typename V>
bool SkipList<K, V>::isValidString(const std::string& str) {
    if(str.empty()) return false;
    if(str.find(':') == std::string::npos) return false;
    return true; 
}