//Addition of two complex numbers

#include<iostream>
using namespace std;
 
 class complex
 {
   float real, img;
   public:
   void get()
   {
    cout<<"Enter real part"<<endl;
     cin>>real;
     cout<<"Enter imaginary part"<<endl;
     cin>>img;
   }  
   complex operator +(complex C)
   {
     complex Cmp;
     Cmp.real=real +C.real;
     Cmp.img=img +C.img;
     return Cmp;
   }
   void display()
   {
     cout<<"Addition of complex numbers is : "<<real<<"+i"<<img<<endl;
   }
 };


 int main()
 {
     complex C1,C2,C3;
     C1.get();
     C2.get();
     C3=C1+C2;
     C3.display();
     return 0;
 }