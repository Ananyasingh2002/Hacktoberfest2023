#include<bits/stdc++.h>
using namespace std;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Vector{
    int*arr;
    int cs;
    int maxSize;
    public:
    Vector(int defalutSize=4){
        maxSize=defalutSize;
        cs=0;
        arr=new int[maxSize];
    }
    void push_back(int data){
        if(cs==maxSize){
            int *oldArr=arr;
            arr=new int[2*maxSize];
            maxSize*=2;
            for(int i=0;i<cs;i++){
                arr[i]=oldArr[i];
            }
            delete []oldArr;
        }
        arr[cs]=data;
        cs++;
    }
    bool empty(){
        return cs==0;
    }
    void pop_back(){
        if(!empty()){
            cs--;
        }
    }
    int&  operator [](int i){
        return arr[i];
    }
    int getSize(){
        return cs;
    }
};
int main(){
    // OJ;
    // FIO;
    // Vector v;
    // v.push_back(4);
    
}