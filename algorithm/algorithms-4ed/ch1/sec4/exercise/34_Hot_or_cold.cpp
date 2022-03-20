/* 1.4.34 Hot or cold. Your goal is to guess a secret integer between 1 and N. You repeat- */
/* edly guess integers between 1 and N. After each guess you learn if your guess equals the */
/* secret integer (and the game stops). Otherwise, you learn if the guess is hotter (closer to) */
/* or colder (farther from) the secret number than your previous guess. Design an algo- */
/* rithm that finds the secret number in at most ~2 lg N guesses. Then design an algorithm */
/* that finds the secret number in at most ~ 1 lg N guesses. */

// Based on http://stackoverflow.com/questions/25558951/hot-and-cold-binary-search-game
// Worst case is O(lg n) + 6 when we start in an "end quarter"
// or O(lg n) + 4 when we start in a "middle quarter"

#include <iostream>
#include <string>

const int MAX = 100;
const int MIN = 1;

int guess(const int secret) {
  auto head = 1;
  auto tail = 100;

  while (head <= tail) {
    auto mid = (head + tail) / 2;
    if (mid > secret) {
      tail = mid - 1;
    } else if (mid < secret) {
      head = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./a.out <number>" << "\n";
  }
  
  std::cout << guess(std::stoi(argv[1])) << "\n";

  return 0;
}
