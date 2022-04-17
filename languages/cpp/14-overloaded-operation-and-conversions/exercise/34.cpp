/* Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter. */

struct Test {
    int operator()(bool b, int iA, int iB) {
        return b ? iA : iB;
    }
};

