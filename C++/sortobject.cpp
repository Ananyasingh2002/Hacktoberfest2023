#include<iostream>
using namespace std;
class A{
    public:
    int marks;char name[50];
    void input();
    void output();
};
void A::input()
{
    cout<<"Enter the name"<<endl;
    cin>>name;
    cout<<"Enter the marks"<<endl;
    cin>>marks;
}
void A::output()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Marks:"<<marks<<endl;
}
int main()
{
    A ob[5];
    for(int i=0;i<5;i++)
    {
        ob[i].input();
    }
    A temp;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(ob[j].marks<ob[j+1].marks)
            {
                temp=ob[j+1];
                ob[j+1]=ob[j];
                ob[j]=temp;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        ob[i].output();
    }
}