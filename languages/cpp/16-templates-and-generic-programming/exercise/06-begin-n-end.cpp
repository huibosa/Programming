/* Exercise 16.6: How do you think the library begin and end functions that */
/* take an array argument work? Define your own versions of these functions. */

#include <iostream>

template<typename _Tp, unsigned N>
_Tp* begin(_Tp (&p)[N]) {
  return p;
}

template<typename _Tp, unsigned N>
_Tp* end(_Tp (&p)[N]) {
  return p + N;
}

int main() {
  int arr[] = {1,2,3,4};
  std::cout << *(begin(arr) + 1) << "\n";
  std::cout << *(end(arr) - 1) << "\n";

  return 0;
}
