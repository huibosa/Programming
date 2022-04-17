#include <set>
#include <string>

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(std::string s): bookNo(s) {}
public:
    std::string isbn() const {return bookNo;}
private:
    std::string bookNo;
};

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    using Less = bool (*)(const Sales_data& lhs, const Sales_data& rhs);
    std::multiset<Sales_data, Less> bookStore(compareIsbn);

    std::multiset<Sales_data, Less>::iterator iter = bookStore.begin();
}
