#include<iostream>
using namespace std;
class A{
    int a;
    int b;
    public:
A()
{
    a=0;
    b=0;
}
A(int x,int y)
{
    a=x;
    b=y;
}
void operator++(int l)//give variable in bracket so that compiler knows it is post increament
{
    //cout<<"post inc"<<endl;
    a=a++;//if we right ++a then increased value will be printed
    b=b++;//here same value us being printed as the value is assigned to 'a' therefore the value will not change
          //(value assigned to 'a' then increased)
}
void operator++()//no variable to be given for pre increament
{
    //cout<<"pre inc"<<endl;
    ++a;//a=++a also returns increased value as a is assigned its increased value here (++ happens first in '++a')
    ++b;
}
void show()
{
    cout<<a<<" "<<b<<endl;
}
};
int main()
{
    A ob1(1,2),ob2(5,6);
    ob1++;//post inc
    ++ob2;//pre inc
    ob1.show();
    ob2.show();
    return 0;
}