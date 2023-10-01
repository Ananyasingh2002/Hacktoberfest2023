#include<iostream>
using namespace std;
class A{
float temper;
public:
operator float(){
    float fer=temper*9/5+32;
    return fer;
}
};
int main(){
    A cel;
    float fer=cel;
    cout<<fer;
}