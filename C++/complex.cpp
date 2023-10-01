#include<iostream>
using namespace std;
class complex{
    float c,d;
    public:
    void input(float a,float b)
    {//cout<<"Enter the complex no. in a+bi form"<<endl;
    c=a;d=b;
    }
void display()
{
    cout<<"The complex no. is "<<c<<"+"<<d<<"i"<<endl;
}
// void sum()
// {
//     int t=a+c;
//     int w=b+d;
//     cout<<"The sum of both the complex nos. "<<t<<"+"<<w<<"i"<<endl;
// }
};
int main()
{
    complex ob,ob1;
    ob.input(8,9);ob1.input(4,5);
    ob.display();ob1.display();
    //ob.sum();

}