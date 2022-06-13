#include <iostream>
#include "./include/skiplist.hpp"

#define FILE_PATH "../store/dumpfile.txt"

int main() {
    SkipList<std::string, std::string> skiplist(6);
    skiplist.insertElement("abcd", "Name");
    skiplist.insertElement("abc", "My");
    skiplist.insertElement("b", "is");
    skiplist.insertElement("c", "HouChen");
    skiplist.insertElement("dc", "ya");
    skiplist.insertElement("fxy", "Nice");
    skiplist.insertElement("gxr", "to");
    skiplist.insertElement("gxr", "to");
    skiplist.insertElement("hij", "Meet");
    skiplist.insertElement("yz", "U");

    std::cout << "skiplist size: " << skiplist.size() << std::endl;
    skiplist.displaySkiplist();
    skiplist.dumpFile();

    skiplist.searchElement("c");
    skiplist.searchElement("zxy");
    skiplist.deleteElement("dc");
    skiplist.updateElement("yz", "you");
    skiplist.displaySkiplist();

    skiplist.loadFile();
    skiplist.displaySkiplist();
    skiplist.clearSkiplist();
    skiplist.displaySkiplist();

    return 0;
}