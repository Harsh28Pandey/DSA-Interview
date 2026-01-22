package OnlinePlatform;

import java.util.*;

public class FourSum {
    public static List<List<Integer>> fourSum(int [] nums, int target){
      int n=nums.length;
        List<List<Integer>>result=new ArrayList<>();
        if(nums==null || nums.length==0){
            return result;
        }
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             for(int k=j+1;k<n;k++){
                 for(int l=k+1;l<n;l++){
                     if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                         result.add(Arrays.asList(nums[i],nums[j],nums[k],nums[l]));
                     }
                 }
             }
         }
     }
     return result;
    }
//    optimize approch for four sum
public static List<List<Integer>> optimizeFourSum(int nums[],int target){
    int n=nums.length;
    List<List<Integer>>result=new ArrayList<>();
    Arrays.sort(nums);
    if(nums==null || n<4){
        return result;
    }
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int left=j+1;
            int right=n-1;
            while(left<right){
                long sum=(long)nums[i]+nums[j]+nums[left]+nums[right];
                if(sum==target) {
                    result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < target) {
                    left++;
                }else{
                    right--;
                }
            }
        }
    }
    return result;
}
    public static void main(String[] args) {
        int []nums = {1000000000,1000000000,1000000000,1000000000};
        int target = -294967296;
        System.out.println(optimizeFourSum(nums,target));
    }
}
