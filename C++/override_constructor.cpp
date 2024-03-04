#include<iostream>
using namespace std;
class A{
public:
A()
{
    cout<<"In A"<<endl;
}
};
class B:public A{
  public:
  B()
  {cout<<"In B"<<endl;}
  A()
  {cout<<"A in B"<<endl;}
};
int main()
{
    B obj;
    return 0;
}