#include<iostream>
using namespace std;
struct player{
    int a;
    float b;
    int f()
    {
        cout<<"hello world"<<endl;
        return 0;
    }
};
int main()
{
   player c;
    c.a=30;
    c.b=78.7;
    int d;
    d=sizeof(c);
    c.f();
    cout<<c.a<<"\n"<<c.b<<endl;
    cout<<sizeof(c)<<endl;
    return 0;
}