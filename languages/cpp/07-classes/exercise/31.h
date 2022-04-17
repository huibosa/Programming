struct Y;

struct X {
  Y* y = nullptr;
};

struct Y {
  X x;
};
