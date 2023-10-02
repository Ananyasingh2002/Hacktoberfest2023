import java.util.*;  
public class SmithNumberExample1  
{  
//function finds the sum of digits of its prime factors  
static int findSumPrimeFactors(int n)  
{  
int i=2, sum=0;  
while(n>1)  
{  
if(n%i==0)  
{  
sum=sum+findSumOfDigit(i);  
n=n/i;  
}  
else  
{  
do  
{  
i++;  
}  
while(!isPrime(i));  
}  
}  
//returns the sum of digits of prime factors  
return sum;  
}  
//function finds the sum of digits of the given numbers  
static int findSumOfDigit(int n)  
{  
//stores the sum  
int s=0;  
while(n>0)  
{  
//finds the last digit of the number and add it to the variable s      
s=s+n%10;  
//removes the last digit from the given number  
n=n/10;  
}  
//returns the sum of digits of the number  
return s;  
}  
//function checks if the factor is prime or not  
static boolean isPrime(int k)  
{  
boolean b=true;  
int d=2;  
while(d<Math.sqrt(k))  
{  
if(k%d==0)  
{  
b=false;  
}  
d++;  
}  
return b;  
}  
//driver code  
public static void main(String args[])  
{  
Scanner sc = new Scanner(System.in);  
System.out.print("Enter a number: ");  
//reads an integer from the user  
int n=sc.nextInt();  
//calling the user-defined function that finds the sum of digits of the given number  
int a = findSumOfDigit(n);  
//calling the user-defined function that finds the sum of prime factors  
int b = findSumPrimeFactors(n);  
System.out.println("Sum of Digits of the given number is = "+a);  
System.out.println("Sum of digits of its prime factors is = "+b);  
//compare both the sums  
if(a==b)  
//prints if above condition returns true  
System.out.print("The given number is a smith number.");  
//prints if above condition returns false  
else  
System.out.print("The given number is not a smith number.");  
}  
}  
