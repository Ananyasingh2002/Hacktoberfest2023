import java.util.Scanner;

public class fibonacci { 
       public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
     System.out.print("Input a number of values in serias you want  : ");
     int n = in.nextInt(); 
     in.close();
        int n1=0,n2=1,n3,i;    
        System.out.print(n1+" "+n2);//printing 0 and 1    
           
        for(i=2;i<n;i++)//loop starts from 2 because 0 and 1 are already printed    
        {    
         n3=n1+n2;    
         System.out.print(" "+n3);    
         n1=n2;    
         n2=n3;    
        }          
    }
    
}
