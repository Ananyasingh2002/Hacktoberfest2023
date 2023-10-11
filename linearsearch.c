#include<stdio.h>
int linearsearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
    {
        return i;
    } else return -1 ;
    }
    
    
    
    
}
int main()
{
    int arr[]={1,3,4,5,6,9,7,8};
    int element=99;
    int size=sizeof(arr)/sizeof(int);
    int searchIndex=linearsearch(arr,size ,element);
    if (searchIndex+1==0)
    {
        printf("The desired element was not found in the array");
    }else
    {
        printf("the element %d was found at %d index of the array",element,searchIndex+1);
    }
    
    
    
    return 0;
}
