template <typename _T1, typename _T2>
int compareTo(const _T1 &lhs, const _T2 &rhs) {
  if (lhs < rhs) {
    return -1;
  } else if (lhs > rhs) {
    return 1;
  } else {
    return 0;
  }
}
