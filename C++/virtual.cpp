#include<iostream>
using namespace std;
class A
{  protected :
int a;
  public:
    A()
    {
        a=70;
    }
};
class B:virtual public A
{
    public:
    B()
    {a=80;}

};
class C:virtual public A
{

 public:
 C()
 {
     a=90;
 }
};
class D:public B,public C
{
 public:
 void display(){
     cout<<B::a;
 }
};
int main()
{
    D ob1;
    ob1.display();
}