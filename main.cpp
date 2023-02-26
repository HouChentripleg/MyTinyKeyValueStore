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

    skiplist.clearSkiplist();
    skiplist.displaySkiplist();
    skiplist.loadFile();
    skiplist.displaySkiplist();

    return 0;
}

/*
inserting element...
insert successfully! key: abcd, value: Name
inserting element...
insert successfully! key: abc, value: My
inserting element...
insert successfully! key: b, value: is
inserting element...
insert successfully! key: c, value: HouChen
inserting element...
insert successfully! key: dc, value: ya
inserting element...
insert successfully! key: fxy, value: Nice
inserting element...
insert successfully! key: gxr, value: to
inserting element...
key: gxr is already exist
inserting element...
insert successfully! key: hij, value: Meet
inserting element...
insert successfully! key: yz, value: U
skiplist size: 9
-------SkipList-------
Level 0: abc:My; abcd:Name; b:is; c:HouChen; dc:ya; fxy:Nice; gxr:to; hij:Meet; yz:U; 
Level 1: abc:My; abcd:Name; b:is; c:HouChen; dc:ya; fxy:Nice; gxr:to; hij:Meet; yz:U; 
Level 2: abc:My; abcd:Name; c:HouChen; dc:ya; fxy:Nice; 
Level 3: abc:My; c:HouChen; fxy:Nice; 
Level 4: abc:My; 
Level 5: abc:My; 
dumping data from memory to file...
dump file successfully!
searching element...
Found Element! key: c, value: HouChen
searching element...
key: zxy, 404 Not Found!
deleting element...
key: dc deleted successfully!
updating element...
key: yz already exists
value: U --> you
-------SkipList-------
Level 0: abc:My; abcd:Name; b:is; c:HouChen; fxy:Nice; gxr:to; hij:Meet; yz:you; 
Level 1: abc:My; abcd:Name; b:is; c:HouChen; fxy:Nice; gxr:to; hij:Meet; yz:you; 
Level 2: abc:My; abcd:Name; c:HouChen; fxy:Nice; 
Level 3: abc:My; c:HouChen; fxy:Nice; 
Level 4: abc:My; 
Level 5: abc:My; 
clearing skiplist...
-------SkipList-------
Level 0: 
loading file to memory...
inserting element...
insert successfully! key: abc, value: My
key: abc value: My
inserting element...
insert successfully! key: abcd, value: Name
key: abcd value: Name
inserting element...
insert successfully! key: b, value: is
key: b value: is
inserting element...
insert successfully! key: c, value: HouChen
key: c value: HouChen
inserting element...
insert successfully! key: dc, value: ya
key: dc value: ya
inserting element...
insert successfully! key: fxy, value: Nice
key: fxy value: Nice
inserting element...
insert successfully! key: gxr, value: to
key: gxr value: to
inserting element...
insert successfully! key: hij, value: Meet
key: hij value: Meet
inserting element...
insert successfully! key: yz, value: U
key: yz value: U
-------SkipList-------
Level 0: abc:My; abcd:Name; b:is; c:HouChen; dc:ya; fxy:Nice; gxr:to; hij:Meet; yz:U; 
Level 1: abc:My; abcd:Name; b:is; c:HouChen; dc:ya; fxy:Nice; gxr:to; hij:Meet; yz:U; 
Level 2: abcd:Name; b:is; fxy:Nice; yz:U; 
Level 3: b:is; fxy:Nice; yz:U; 
Level 4: fxy:Nice; yz:U; 
Level 5: fxy:Nice; 
*/