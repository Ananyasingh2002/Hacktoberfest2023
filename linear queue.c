#include<stdio.h>
#include<stdlib.h>
#define max 10
int f=-1,r=-1;
void enqueue(int item,int a[])
{
	if(r==max-1)
	{
		printf("Overflow");
	}
	else if(f==-1 && r==-1)
	{
		f=r=0;
		a[r]=item;
	}
	else
	{
		r=r+1;
		a[r]=item;
	}
}
void dequeue()
{
	if(r==-1)
	{
		printf("Underflow");
	}
	else
	{
		r=r-1;
	}
}
void display(int a[])
{
	int i;
	if(r==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		for(i=0;i<=r;i++)
		{
			printf("%d ",a[i]);
		}
	}
}
int main()
{
	int a[max],item,c;
	
	while(1)
	{
		printf("\n1......Enqueue");
		printf("\n2......Dequeue");
		printf("\n3......display");
		printf("\n4......Exit");
		
		printf("\nEnter your choose:");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:
				printf("\nEnter a number:");
				scanf("%d",&item);
				enqueue(item,a);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display(a);
				break;
			case 4:
				exit(0);
		}
	}
}
