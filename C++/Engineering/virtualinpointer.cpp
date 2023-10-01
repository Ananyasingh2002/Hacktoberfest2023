#include<iostream>
using namespace std;
class A
{
    public:
    virtual void show(){cout<<"hi\n";}
};
class B:public A
{
    public:
    void show(){cout<<"hello\n";}
};
int main()
{
    A *ob=new B;
    ob->show();//output is hi   if we add virtual then output is hello
}