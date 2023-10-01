#include<iostream>
using namespace std;
class Distance{
    int feet;
    int inches;
    public:
Distance(){
    feet=0;
  inches=0;
}
Distance(int f,int i)
{
    feet=f;
    inches=i;
}
void display()
{
    cout<<"Feet:"<<feet<<endl;
    cout<<"Inches:"<<inches<<endl;
}
Distance operator-()
{
    feet=-feet;
    inches=-inches;
    return Distance(feet,inches);
}
};
int main()
{
    Distance D1(10,20),D2(45,52);
    -D1;
    D1.display();
    -D2;
    D2.display();
    return 0;
}