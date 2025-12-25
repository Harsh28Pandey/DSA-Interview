package CoderArmy;

public class SumOfSubset {
    public static boolean subsetsum(int nums[],int n,int sub,int target){
        if(sub==target){
            return true;
        }
        if(n==0){
            return false;
        }
//      include
        boolean include=   subsetsum(nums,n-1,sub+nums[n-1],target);
        //exclude
          boolean exclude= subsetsum(nums,n-1,sub,target);
        return include || exclude;
    }

    public static void main(String[] args) {
        int nums[]={1,2,3};
        int subset=0;
        System.out.println(subsetsum(nums,nums.length,subset,3));
    }
}
