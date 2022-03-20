// Write a Screen class template that uses nontype
// parameters to define the height and width of the Screen.

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <ostream>
#include <string>

template <unsigned, unsigned> class Screen;

template <unsigned _Ht, unsigned _Wd>
std::ostream &operator<<(std::ostream &, const Screen<_Ht, _Wd> &);

template <unsigned _Ht, unsigned _Wd>
std::istream &operator>>(std::istream &, Screen<_Ht, _Wd> &);

template <unsigned _Ht, unsigned _Wd> class Screen {
  friend std::ostream &operator<< <_Ht, _Wd>(std::ostream &, const Screen &);
  friend std::istream &operator>> <_Ht, _Wd>(std::istream &, Screen &);

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
std::ostream &operator<<(std::ostream &os, const Screen<_Ht, _Wd> &rhs) {
  for (int i = 0; i < rhs.height; ++i) {
    os << rhs.contents.substr(0, _Wd) << "\n";
  }
  return os;
}

template <unsigned _Ht, unsigned _Wd>
std::istream &operator>>(std::istream & is, Screen<_Ht, _Wd> &rhs) {
  char c;
  is >> c;
  rhs.contents = std::string(_Ht *_Wd, c);
  return is;
}

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
