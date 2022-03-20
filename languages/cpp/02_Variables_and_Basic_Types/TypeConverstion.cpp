#include <iostream>
using namespace std;

int main() {
    unsigned u = 10;
    int i = -42;
    cout << i + i << endl;  // print -84
    cout << u + i << endl;  // if 32-bit, print 4294967264

    unsigned u1 = 42;
    unsigned u2 = 10;
    cout << u1 - u2 << endl;    // print 32
    cout << u2 - u1 << endl;    // result wrap around

    for (int i = 0; i >= 0; --i) {
        cout << i << endl;
    }
    // infinite loop
    for (unsigned i = 0; i >= 0; --i) {
        cout << i << endl;
    }
    // consider using a while loop
    unsigned u4 = 11;
    while (u > 0) {
        --u;
        cout << u << endl;
    }
}
