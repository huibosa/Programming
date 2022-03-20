/* 2.1.13    Deck sort. Explain how you would put a deck of cards in order by suit (in the */ 
/* order spades, hearts, clubs, diamonds) and by rank within each suit, with the restriction */ 
/* that the cards must be laid out face down in a row, and the only allowed operations are */ 
/* to check the values of two cards and to exchange two cards (keeping them face down). */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <functional>

static bool check(std::vector<int>& a) {
  std::unordered_map<int, int> valuesMap;

  // Insert all values in the map
  for (const auto& val : a) {
    if (valuesMap.find(val) != valuesMap.end()) {
      valuesMap[val]++;
    } else {
      valuesMap[val] = 1;
    }
  }

  sort(a.begin(), a.end());

  // check if array is sorted
  std::greater<int> greater;
  for (int i = 0; i < a.size(); ++i) {
    if (greater(a[i], a[i+1])) {
      return false;
    }
  }

  // check if the initial set of objects is still in the array
  for (const auto& val : a) {
    if (valuesMap.find(val) != valuesMap.end()) {
      valuesMap[val]--;
      if (valuesMap[val] == 0) {
        valuesMap.erase(val);
      }
    } else {
      return false;
    }
  }

  if (valuesMap.empty()) {
    return true;
  }
  
  return false;
}
