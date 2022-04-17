// Write a Screen class template that uses nontype
// parameters to define the height and width of the Screen.

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <ostream>
#include <string>

template <unsigned _Ht, unsigned _Wd> class Screen {
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(char c) : contents(_Ht * _Wd, c) {}
  char get() const { return contents[cursor]; }
  char get(pos r, pos c) const;
  Screen &move(pos r, pos c);

private:
  std::string contents;
  pos cursor = 0;
  pos height = _Ht;
  pos width = _Wd;
};

template <unsigned _Ht, unsigned _Wd>
inline char Screen<_Ht, _Wd>::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

template <unsigned _Ht, unsigned _Wd>
Screen<_Ht, _Wd> &Screen<_Ht, _Wd>::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

#endif /* 14_SCREEN_H */
