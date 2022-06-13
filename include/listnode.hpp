#pragma once

#include <iostream>
#include <memory>

template<typename K, typename V>
class ListNode {
private:
    K key_;
    V value_;
    int nodeLevel_;
public:
    ListNode<K, V>** forward_;   // forward二级指针存储一个指针数组的地址，该指针数组中存储着当前节点的所有索引层中指向下一个节点的指针
public:
    ListNode() : forward_(nullptr) {};
    ListNode(K, V, int);
    ListNode(const ListNode&) = delete;
    ListNode& operator=(const ListNode&) = delete;
    ListNode& operator=(ListNode&&) = delete;
    ~ListNode() {
        delete[] forward_;
    }

    K getKey() const {
        return key_;
    }
    V getValue() const {
        return value_;
    }
    V setValue(V val) {
        return this->value_ = val;
    }
    int getLevel() {
        return nodeLevel_;
    };
};

template<typename K, typename V>
ListNode<K, V>::ListNode(K k, V v, int level) : key_(k), value_(v), nodeLevel_(level) {
    this->forward_ = new ListNode<K, V>*[level + 1]; // 原始层+索引层
    memset(this->forward_, 0, sizeof(this->forward_));    // 指针数组初值赋0
}
