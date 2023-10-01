#include<iostream>
using namespace std;
class V{
    public://class made public
    int a,b;
    void input()//taking input a and b
    {
        cout<<"enter a and b"<<endl;
        cin>>a>>b;
    }
    void output()//printing a and b
    {
        cout<<"a and b after swapping="<<endl<<a<<endl<<b;
    }
    void swap()//swapping
    {
        int t=a;
        a=b;
        b=t;
    }
};
int main()
{
    V ob;//made object of class
    ob.input();//calling each fuction in it
    ob.swap();
    ob.output();

}