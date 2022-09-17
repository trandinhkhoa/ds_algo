#include "removeDups.h"
#include <iostream>
#include <unordered_set>

// the implementation of the hash table depends on the type of the list
// .e.g list of chars => simple hash table that maps chars ascii value to index
// list of number/string/etc. => how?
// map vs unordered map vs unordered set vs set
// emplace vs insert
// insert copies objects into the vector.
// emplace construct them inside of the vector.
// https://stackoverflow.com/questions/69558136/is-there-ever-a-time-where-insert-is-better-than-emplace-on-a-map-in-c
// emplace vs emplace_back vs emplace_front
// pointer vs iterator: iterator is similar but capable of more
// complexity ?
void cracking::linkedLists::removeDups(std::list<int>& iList) {
  std::list<int>::iterator aIter = iList.begin();
  std::unordered_set<int> aBuffer;
  while (aIter != iList.end()) {
    std::list<int>::iterator aIterCopy = aIter;
    aIter++;
    if (aBuffer.find(*aIterCopy) != aBuffer.end()) {
      iList.erase(aIterCopy);
      // remove
    } else {
      aBuffer.emplace(*aIterCopy);
    }
  }
}



void cracking::linkedLists::removeDups_withoutBuffer(std::list<int>& iList) {
  if (iList.size() < 2) {
    return;
  }

  std::list<int>::iterator aIter_1 = iList.begin();
  while (aIter_1 != std::prev(iList.end(), 1)) {
    std::list<int>::iterator aIter_2 = aIter_1;
    aIter_2++;

    while (aIter_2 != iList.end()) {
      if (*aIter_2 == *aIter_1) {
        // erase aIterCopy will also aIter_2 (they are positions) so we increment aIter_2
        std::list<int>::iterator aIterCopy = aIter_2;
        aIter_2++;
        iList.erase(aIterCopy);
      } else {
        aIter_2++;
      }
    }
    aIter_1++;
  }
}