#include <iostream>
using namespace std;

class testBase
{
private:
    /* data */
public:
    testBase(/* args */);
    virtual void foo() {
        cout << "base foo" << endl;
    }
    ~testBase();
};

testBase::testBase(/* args */)
{
    cout << "base ctor" << endl;
    foo();
}

testBase::~testBase()
{
}


class Son : public testBase
{
private:
    /* data */
public:
    Son(/* args */);
    virtual void foo(){
        cout << "son foo\n";
    }
    ~Son();
};



Son::Son(/* args */)
{
}

Son::~Son()
{
}


int main()
{
    testBase* t = new testBase;
    Son* s = new Son;
}