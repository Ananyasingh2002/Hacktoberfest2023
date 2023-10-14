#include<stdio.h>
#include<stdlib.h>
void Create(int *arr,int len){
for(int i = 0;i<len;i++){
printf("Enter the value at index %d : ",i);
scanf("%d",arr+i);
}
}
void swap(int *a, int *b){
int temp = *a;
*a = *b;
*b = temp;
}
void display(int arr[],int len){
printf("\n");
for(int i = 0; i<len;i++){
printf("%d\t",arr[i]);
}
printf("\n");
}
int* insert(int *arr,int len,int index,int val){
if(index>len || index<0){
return NULL;
}
(len)++;
int *arr1 = (int*)malloc(sizeof(int*)*(len));
for(int i = 0;i<index;i++){
*(arr1+i) = *(arr + i);
}
*(arr1 + index) = val;
for(int i = index+1;i<len;i++){
*(arr1+i) = *(arr+i-1);
}
arr = arr1;
return arr;
}
int* delete(int *arr,int len,int index){
if(index>len || index<0){
return NULL;
}
len--;
int *arr1 = (int*)malloc(sizeof(int*)*(len));
for(int i = 0;i<index;i++){
*(arr1+i) = *(arr + i);
}
for(int i = index;i<len;i++){
*(arr1+i) = *(arr+i+1);
}
arr = arr1;
return arr;
}
int* sort(int* arr, int len){
for(int i = 0; i<len; i++){
for(int j = 0; j<len-i-1; j++){
if(*(arr+j)>*(arr+j+1)){
swap((arr+j),(arr+j+1));
}
}
}
return arr;
}
int main(){
int len,val;
printf("Creating array\nenter length of array : ");
scanf("%d",&len);
int *arr = (int*)malloc(sizeof(int*)*len);
Create(arr,len);
int option,exit_status = 0;
do{
printf("\nSelect the below option:\n\n");
printf("1.display the array\n");
printf("2.insertion\n");
printf("3.deletion\n");
printf("4.length of array\n");
printf("5.sort array\n");
printf("6.update\n");
printf("7.exit\n\nEnter Your option:");
scanf("%d",&option);
printf("\n**************************************************
****\n");
int index,val;
switch (option)
{
case 1:
display(arr,len);
break;
case 2:
printf("Enter the index of inserting : ");
scanf("%d",&index);
printf("Enter the value for inserting : ");
scanf("%d",&val);
arr = insert(arr,len,index,val);
len++;
break;
case 3:
printf("\nEnter the index of deletion : ");
scanf("%d",&index);
arr = delete(arr,len,index);
len--;
break;
case 4:
printf("\nlength of linked list is %d\n",len);
break;
case 5:
printf("\nthe array is sorted\n");
arr = sort(arr,len);
break;
case 6:
printf("Enter the index of updating : ");
scanf("%d",&index);
printf("Enter the value for updating : ");
scanf("%d",&val);
arr[index] = val;
break;
case 7:
printf("exiting.....\n");
exit_status = 1;
break;
default:
printf("enter the valid option\n");
break;
}
printf("\n**************************************************
****\n");
}
while(exit_status != 1);
return 0;
}
