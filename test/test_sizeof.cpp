#include <iostream>
using namespace std;

int main()
{
    int **p[3][4];
    cout << sizeof(p) << endl;
    char *a[] = {"hello","world"};
    cout << sizeof(a) << endl;
    char ch[] = "hello";
    cout << sizeof(ch) << endl;
    char *pch = "hello";
    cout << sizeof(pch) << endl;
    char** pp[3][4];
    cout << sizeof(pp) << endl;
}