
import Java.util.*;   
import java.io.*;   
import java.util.Scanner;  
  

class TSPExample   
{  
     
    static int findHamiltonianCycle(int[][] distance, boolean[] visitCity, int currPos, int cities, int count, int cost, int hamiltonianCycle)   
    {  
    
        if (count == cities && distance[currPos][0] > 0)   
        {  
            hamiltonianCycle = Math.min(hamiltonianCycle, cost + distance[currPos][0]);  
            return hamiltonianCycle;  
        }  
    
      
        for (int i = 0; i < cities; i++)   
        {  
            if (visitCity[i] == false && distance[currPos][i] > 0)   
            {  
    
               
                visitCity[i] = true;  
                hamiltonianCycle = findHamiltonianCycle(distance, visitCity, i, cities, count + 1, cost + distance[currPos][i], hamiltonianCycle);  
    
               
                visitCity[i] = false;  
            }  
        }  
        return hamiltonianCycle;  
    }  
    
   
    public static void main(String[] args)  
    {  
        int cities;  
        
        Scanner sc = new Scanner(System.in);  
          
      
        System.out.println("Enter total number of cities ");  
        cities = sc.nextInt();  
          
          
       
        int distance[][] = new int[cities][cities];  
        for( int i = 0; i < cities; i++){  
            for( int j = 0; j < cities; j++){  
                System.out.println("Distance from city"+ (i+1) +" to city"+ (j+1) +": ");  
                distance[i][j] = sc.nextInt();  
            }  
        }  
    
        
        boolean[] visitCity = new boolean[cities];  
    
      
        visitCity[0] = true;  
          
          
        int hamiltonianCycle = Integer.MAX_VALUE;  
    
        
        hamiltonianCycle = findHamiltonianCycle(distance, visitCity, 0, cities, 1, 0, hamiltonianCycle);  
    
        
        System.out.println(hamiltonianCycle);  
    }  
}  
