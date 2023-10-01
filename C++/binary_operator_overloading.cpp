#include<iostream>
using namespace std;
class Location{
int longi;
int lati;
public:
Location()
{
    longi=0;
    lati=0;
}
Location(int lo,int la)
{
    longi=lo;
    lati=la;
}
void display()
{
    cout<<"Longitude of the resultant place is:"<<longi<<endl;
    cout<<"Latitude of the resultant place is:"<<lati<<endl;
}
Location operator+(Location L1)
{
    Location temp;
    temp.longi=longi+L1.longi;
    temp.lati=lati+L1.lati;
    return temp;
}
};
int main()
{
    Location D1(10,20),D2(45,52);
    Location D3;
    D3=D1+D2;
    D3.display();
    return 0;
}