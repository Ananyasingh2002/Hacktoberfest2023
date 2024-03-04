#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
int max_cross_sum(int A[], int p, int mid, int r)
{
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i=mid; i>=p; i--)
    {
    sum = sum+A[i];
    if (sum>left_sum)
       left_sum=sum;
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i=mid+1;i<=r;i++)
    {   
        sum=sum+A[i];
        if (sum>right_sum)
           right_sum = sum;
    }
    return (left_sum+right_sum);
}
int max_subarray_sum(int A[],int p,int r){
    if(p==r){
        return A[p];
    }
    int mid=(r+p)/2;
    int left_sum=max_subarray_sum(A,p,mid);
    int right_sum=max_subarray_sum(A,mid+1,r);
    int cross_sum=max_cross_sum(A,p,mid,r);
    return max(max(left_sum,right_sum),cross_sum);
}
// int max_cross_sum(int A[], int p, int mid, int r)
// {
//     int left_sum = INT_MIN;
//     int sum = 0;
//     for (int i=mid; i>=p; i--)
//     {
//     sum = sum+A[i];
//     if (sum>left_sum)
//        left_sum=sum;
//     }
//     int right_sum = INT_MIN;
//     sum = 0;
//     for (int i=mid+1;i<=r;i++)
//     {   
//         sum=sum+A[i];
//         if (sum>right_sum)
//            right_sum = sum;
//     }
//     return (left_sum+right_sum);
// }
int main()
{
    int a[]={-2,-5,6,-2,-3,1,5,-6};
    int n=sizeof(a)/sizeof(a[0]);
    int ans=max_subarray_sum(a,0,n-1);
    cout<<ans<<endl;
    return 0;
}