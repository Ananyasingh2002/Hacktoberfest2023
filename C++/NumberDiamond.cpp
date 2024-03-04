#include<iostream>
using namespace std;
int main()
{
    /*
   n= 5
  1
 232
34543
 232
  1*/
    int n;
    cin>>n;
    int sp = n/2;  //space
    int st = 1;   //star
    int val = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sp;j++){
            cout<<" ";
        }
        int cval=val;
        for(int j=1;j<=st;j++){
            cout<<cval;
         
            if(j<=st/2){
                cval++;
            }else{
                cval--;
            }
            
        }
        if(i<=n/2){ 
            sp--;
            st+=2;
            val++;
        }else{
            sp++;
            st-=2;
            val--;
        }
        cout<<endl;

    }
    return 0;
}