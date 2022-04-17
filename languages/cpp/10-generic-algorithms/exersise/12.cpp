#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>

struct Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string& s): bookNo(s) { }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

bool compareIsbn(const Sales_data& s1, const Sales_data& s2) {
    return s1.isbn() < s2.isbn();
}

void printIsbn(const Sales_data& s) {
    std::cout << s.isbn() << " ";
}

int main() {
    std::vector<Sales_data> vec {
        Sales_data("when"), Sales_data("working"), Sales_data("with"),
        Sales_data("tabular"), Sales_data("data"), Sales_data("such"),
        Sales_data("as"), Sales_data("data"), Sales_data("stored"),
        Sales_data("in"), Sales_data("spreadsheets"), Sales_data("or"),
        Sales_data("databases"), Sales_data("pandas"), Sales_data("is"),
        Sales_data("the"), Sales_data("right"), Sales_data("tool"),
        Sales_data("for"), Sales_data("you"), Sales_data("pandas"),
        Sales_data("will"), Sales_data("help"), Sales_data("you"),
        Sales_data("to"), Sales_data("explore"), Sales_data("clean"),
        Sales_data("and"), Sales_data("process"), Sales_data("your"),
        Sales_data("data"), Sales_data("in"), Sales_data("pandas"),
        Sales_data("a"), Sales_data("data"), Sales_data("table"),
        Sales_data("is"), Sales_data("called"), Sales_data("a"), Sales_data("dataframe")
    };

    std::sort(vec.begin(), vec.end(), compareIsbn);
    // std::for_each(vec.begin(), vec.end(), [](const Sales_data& s) { std::cout << s.isbn() << " "; });
    std::for_each(vec.begin(), vec.end(), printIsbn);
    std::cout << std::endl;
};
