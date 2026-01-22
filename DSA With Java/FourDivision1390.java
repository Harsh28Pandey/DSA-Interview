package OnlinePlatform;

public class FourDivision1390 {
    public static int sumFourDivision(int []nums,int n,int total){
        if(n==0){
            return total;
        }
        int count=0;
        int add=0;
        for(int i=1;i*i<=nums[n-1];i++) {
            if (nums[n - 1] % i == 0) {
                count++;
                add += i;

                if (i != nums[n - 1] / i) {
                    count++;
                    add += nums[n - 1] / i;
                }
            }
        }
        if(count==4){
            total+=add;
        }
        return sumFourDivision(nums,n-1,total);
    }

    public static void main(String[] args) {
        int nums[]={21,21};
        System.out.println(sumFourDivision(nums,nums.length,0));
    }
}
