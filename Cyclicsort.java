import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args) {
    int [] arr={3,5,4,2,1};
    cyclicsort(arr);
    System.out.println(Arrays.toString(arr));
    }

    static void cyclicsort(int [] arr){
        int i=0;
        while(i<arr.length){
            int correctpos=arr[i]-1;
            if(arr[correctpos] != arr[i]){
                swap(arr,correctpos,i);

            }
            else{
                i++;//move forward
            }
        }
    }

     static void swap(int[] arr, int correctpos, int i) {
            int temp=arr[correctpos];
            arr[correctpos]=arr[i];
            arr[i]=temp;
    }

}
