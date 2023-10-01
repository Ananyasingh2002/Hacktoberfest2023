#include<iostream>
using namespace std;
class complex{
    float r,i;
    public:
    void input();
    void output();
    complex sum(complex c1);
};
void complex::input()
{
    cout<<"Enter the complex no. in a+ib form"<<endl;
    cin>>r>>i;
}
void complex::output()
{
   cout<<"The sum is "<<r<<"+i"<<i;
}
complex complex::sum(complex c1)
{
    complex c3;
    c3.r=c1.r+r;
    c3.i=c1.i+i;
    return c3;
}
int main()
{
    complex ob1,ob2,ob3;
    ob1.input();ob2.input();
    ob3=ob1.sum(ob2);//in this step ob2 will be assigned to c1 so c1.r will pick value 
                     //of r in ob1 and the +r will be of ob1 as we are calling sum in 
                     //ob1.the sum will be stored in c3 which perhaps is ob3.
    ob3.output();                 
}