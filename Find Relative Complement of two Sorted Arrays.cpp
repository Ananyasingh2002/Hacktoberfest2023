#include <iostream>  
using namespace std;  
  
void relComp(int array1[], int array2[],  
                            int p, int q) {  
  
int i = 0, j = 0;  
while (i < q && j < p) {  
  
    //If the current element in array2[] is larger, therefore array1[i] cannot be included in array2[j..p-1].  
    if (array1[i] < array2[j]) {  
    cout << array1[i] << " ";  
    i++;  
  
    // Smaller elements of array2[] are skipped  
    } else if (array1[i] > array2[j]) {  
    j++;  
  
    // Same elements detected (skipping in both arrays)  
    } else if (array1[i] == array2[j]) {  
    i++;  
    j++;  
    }  
}  
  
// Printing the remaining array1 items[]  
while (i < q)  
    cout << array1[i] << " ";  
}  
  
// Driver code  
int main() {  
int array1[] = {3, 6, 10, 12, 15};  
int array2[] = {1, 3, 5, 10, 16};  
int q = sizeof(array1) / sizeof(array1[0]);  
int p = sizeof(array2) / sizeof(array2[0]);  
relComp(array1, array2, q, p);  
return 0;  
}  
