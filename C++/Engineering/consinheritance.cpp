#include<iostream>
using namespace std;
class A{
    public:
    A(){cout<<"Contructor of A"<<endl;}
    ~A(){cout<<"Destructor of A"<<endl;}
};
class B{
    public:
    B(){cout<<"Contructor of B"<<endl;}
    ~B(){cout<<"Destructor of B"<<endl;}
};
class C:public B,public A{
public:
C(){cout<<"Contructor of C"<<endl;}
~C(){cout<<"Destructor of C"<<endl;}
};
int main()
{
    C ob1;
}