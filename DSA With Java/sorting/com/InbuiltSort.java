package sorting.com;

import java.util.Arrays;
import java.util.Collections;
public class InbuiltSort {
    public static void main(String[] args) {
        Integer arr[]={4,5,3,1,2};
//        Arrays.sort(arr); //simply sort an array in ascending order and output=> 1 2 3 4 5
//        Arrays.sort(arr,0,3);//this method sort and array in ascending order according to
        // specified index from specified starting to specified ending ending output=> 3 4 5 1 2
//        Arrays.sort(arr,Collections.reverseOrder()); //this mathod sort an array in descending order but it
        // requires array object means integer not int its a primitive data type
        Arrays.sort(arr,3,5,Collections.reverseOrder());// this method is used to sort an array in
        // descending order according to specified starting and ending position
          for (int i=0;i< arr.length;i++){
          System.out.print(arr[i]+" ");
      }
    }
}
