#include<iostream>
using namespace std;
class A{
    int a,b;
public:
A(int c,int d){
cout<<"Contructor Input values of a and b"<<endl;
a=c;b=d;
}//constructor with no arguments is called default or empty constructor
void display()
{
    cout<<"Values of a and b "<<a<<" "<<b<<endl;
}
~A()
{
    cout<<"Destructor is called for every object"<<endl;
}
};
int main()
{
A ob(8,9),ob1(10,11);
ob.display();ob1.display();
}