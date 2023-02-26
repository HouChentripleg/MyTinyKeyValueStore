#include <iostream>
#include <chrono>
#include <pthread.h>
#include "../include/skiplist.hpp"

#define THREADS_NUM 10
#define TEST_CNT 100000
SkipList<std::string, std::string> skiplist(18);

void* insertElement(void* threadID) {
    long tid = reinterpret_cast<long>(threadID);
    std::cout << tid << std::endl;
    int tmp = TEST_CNT / THREADS_NUM;
    for(int i = tid * tmp, cnt = 0; cnt < tmp; i++) {
        ++cnt;
        skiplist.insertElement(std::to_string(rand() % TEST_CNT), "HouChen");
    }
    pthread_exit(nullptr);
}

/*
void* getElement(void* threadID) {
    long tid = reinterpret_cast<long>(threadID);
    std::cout << tid << std::endl;
    int tmp = TEST_CNT / THREADS_NUM;
    for(int i = tid * tmp, cnt = 0; cnt < tmp; i++) {
        ++cnt;
        skiplist.searchElement(std::to_string(rand() % TEST_CNT));
    }
    pthread_exit(nullptr);
}

void* updateElement(void* threadID) {
    long tid = reinterpret_cast<long>(threadID);
    std::cout << tid << std::endl;
    int tmp = TEST_CNT / THREADS_NUM;
    for(int i = tid * tmp, cnt = 0; cnt < tmp; i++) {
        ++cnt;
        skiplist.updateElement(std::to_string(rand() % TEST_CNT), "HouChen");
    }
    pthread_exit(nullptr);
}

void* deleteElement(void* threadID) {
    long tid = reinterpret_cast<long>(threadID);
    std::cout << tid << std::endl;
    int tmp = TEST_CNT / THREADS_NUM;
    for(int i = tid * tmp, cnt = 0; cnt < tmp; i++) {
        ++cnt;
        skiplist.deleteElement(std::to_string(rand() % TEST_CNT), "HouChen");
    }
    pthread_exit(nullptr);
}
*/

int main() {
    srand(time(nullptr));
    {
        pthread_t threads[THREADS_NUM];
        int rc;
        int i;
        auto start = std::chrono::high_resolution_clock::now();

        for(int i = 0; i < THREADS_NUM; i++) {
            std::cout << "main() : creating thread, " << i << std::endl;
            rc = pthread_create(&threads[i], nullptr, insertElement, (void*)i);
            if(rc) {
                std::cout << "Error: unable to create thread, " << rc << std::endl;
                exit(-1);
            }
        }

        void* ret;
        for(i = 0; i < THREADS_NUM; i++) {
            if(pthread_join(threads[i], &ret) != 0) {
                perror("pthread_create() error");
                exit(3);
            }
        }

        auto finish = std::chrono::high_resolution_clock::now();
        std::cout << "insertion time: " << std::chrono::duration<double>(finish - start).count() << std::endl;
    }

    /*
    {
        pthread_t threads[THREADS_NUM];
        int rc;
        int i;
        auto start = std::chrono::high_resolution_clock::now();

        for(int i = 0; i < THREADS_NUM; i++) {
            std::cout << "main() : creating thread, " << i << std::endl;
            rc = pthread_create(&threads[i], nullptr, searchElement, (void*)i);
            if(rc) {
                std::cout << "Error: unable to create thread, " << rc << std::endl;
                exit(-1);
            }
        }

        void* ret;
        for(i = 0; i < THREADS_NUM; i++) {
            if(pthread_join(threads[i], &ret) != 0) {
                perror("pthread_create() error");
                exit(3);
            }
        }

        auto finish = std::chrono::high_resolution_clock::now();
        std::cout << "insertion time: " << std::chrono::duration<double>(finish - start).count() << std::endl;
    }
    */

   pthread_exit(nullptr);
   return 0;
}