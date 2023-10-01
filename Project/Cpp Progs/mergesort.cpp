#include<iostream>//Preprocessig Directives
using namespace std;//calling objects from predefined namespace
void merge(int [],int,int,int);//declaratin of function
void mergesort(int [],int,int);//declaration of recursive mergesort function
void display(int [],int);           //declaration of display function

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int A[n];   //declaring array of size n
    cout<<"Enter the no of elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>A[i];   //taking elements as input
    mergesort(A,0,n-1);
    display(A,n);

}
// merge function
void merge(int A[],int low,int mid,int high)
{
    int n1=mid-low+1,n2=high-mid;
    int* left = new int[n1];       //left half array pointer
    int* right = new int[n2];      //right half array pointer
    
    for(int i=0;i<n1;i++)
     left[i]=A[low+i];     //adding elements in first half of the array
    for(int j=0;j<n2;j++)
      right[j]=A[mid+j+1];   //adding elements in second half of the array
    
    int i=0,j=0,k=low;
    while(i<n1&&j<n2)       //Code to Merge to array in sorted manner
    {
        if(left[i]<=right[j])
            A[k++]=left[i++];
        else
            A[k++]=right[j++];
    }
    while(i<n1)
        A[k++]=left[i++];       //Processing elements remaining in left array
    while(j<n2)
        A[k++]=right[j++];      //Processing elements remaining in right array

    delete[] left;              //freeing memory after use
    delete[] right;
}
//Mergesort function
void mergesort(int arr[],int l,int h)
{
    if(h>l)
    {
        int m=(l+h)/2;  //calculating the middle index
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}
//display function
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    cout<<"\n";
}

