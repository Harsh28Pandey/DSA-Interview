package OnlinePlatform;

import java.util.ArrayList;
import java.util.Arrays;

public class MaximizeHappiness3075leetcode {
    //approch implemented by me
    public static long maximizeHappinessSum1(int []happiness,int k){
        Arrays.sort(happiness);
       long sum=0;
       int temp=0;
       int n=happiness.length;
       while(k>0){
           temp++;
           sum+=happiness[n-temp];
           for(int i=0;i<n-temp;i++){
               happiness[i]=happiness[i]-1;
           }
           for(int i=0;i<n-temp;i++){
               if(happiness[i]<0){
                   happiness[i]=0;
               }
           }
           k--;
       }
        return sum;
    }

//    optimized approach given by gpt
public static long maximizeHappinessSum2(int[] happiness, int k) {
    Arrays.sort(happiness);
    long sum = 0;
    int n = happiness.length;

    for (int i = 0; i < k; i++) {
        int val = happiness[n - 1 - i] - i;
        if (val <= 0) break;
        sum += val;
    }
    return sum;
}

    public static void main(String[] args) {
        int happiness[]={1,2,3};
        int k=2;
        System.out.println(maximizeHappinessSum1(happiness,k));
    }
}
