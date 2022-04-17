#include <iostream>
using namespace std;

int main() {
    cout << "a really, really long string literal "
            "that spans two lines" << std::endl;

    cout << '\n';
    cout << "\tHi!\n";

    cout << "Hi  \x4dO\155!\n";
    cout << '\115' << '\n';

    /* L'a'      wide character literal, type is wchar_t                            */
    /* u8"hi!"   utf-8 string literal (utf-8 encodes a Unicode character in 8 bits) */
    /* 42ULL     unsigned integer literal, type is unsigned long long               */
    /* 1E-3F     single-precision floating-point literal, type is float             */
    /* 3.14159L  extended-precision floating-point literal, type is long double     */
}
