#include <iostream>
#include <string>
using namespace std;

extern int i;
extern double pi = 3.1416;

int main() {
    int sum = 0, value;
    unsigned unit_sold = 0;
    Sales_item item;
    string book("0-201-78345-X");

    double price = 109.99, discount = price * 0.16;
    double salesPrice = applyDiscount(price, discount);

    // list initialization
    int unit_sold = 0;
    int unit_sold = {0};
    int unit_sold{0};
    int unit_sold(0);

    long double ld = 3.1415926536;
    int a{ld}, b = {ld};    // error, narrowing conversion required
    inc c(ld), d(ld);       // ok, but value will be truncated

    string empty;           // implicitly initialized to empty string
    Sales_item item;        // default-initialized Sales_item object
}
