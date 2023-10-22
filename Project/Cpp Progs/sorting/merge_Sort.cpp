#include<iostream>
using namespace std;
void merge(int ar[],int beg,int mid,int end)
{

    //int i,j,k;
    int n1=mid-beg+1;
    int n2=end-mid;
    //temporary arrays :left and right ;
    int ar1[n1];
    int ar2[n2];
   //copying element to both temp. arrays;
   for(int i=0;i<n1;i++)
   {
    ar1[i]=ar[beg +i];
   }

   for(int j=0;j<n2;j++)
   { 
    ar2[j]=ar[mid+1+j];
   }

    int i=0;
    int j=0;
    int k=beg;

    //sorting
    while(i<n1 && j<n2){
        if(ar1[i]<=ar2[j])
        {
            ar[k++]=ar1[i++];
            
        }else
        {
            ar[k++]=ar2[j++];
        }
    }

    while(i<n1){
        ar[k++]=ar1[i++];
    }
    while(j<n2){
        ar[k++]=ar2[j++];
    }

}
void mergesort(int a[],int beg,int end)
{
    if(beg<end){
        int mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void printarray(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int  main(){
    int a[]={ 11, 30, 24, 7, 31, 16, 39, 41 };
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"array before sorting"<<endl;
    printarray(a,n);
    
    mergesort(a,0,n-1);
    cout<<"after sorting array is";
    printarray(a,n);
    return 0;
}