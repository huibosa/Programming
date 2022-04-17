// The following definition of List is incorrect. How would you fix it?

template<typename elemType> class ListItem;

template<typename elemType> class List {
public:
  List();
  List(const List&);
  List& operator=(const List &);
  ~List();

  void insert(ListItem<elemType> *ptr, elemType value);
private:
  ListItem<elemType>* front;
  ListItem<elemType>* end;
};

int main() {
  List<int> foo;

  return 0;
}
