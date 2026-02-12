package OnlinePlatform;

public class ContainerWithMostWater {
    public static int maxArea(int height[]){
        int left=0;
        int right=height.length-1;
        int maxWater=Integer.MIN_VALUE;
        int water=0;
        while(left<right){
            int waterHeight=Math.min(height[left],height[right]);
            int width=right-left;
            water=width*waterHeight;
            maxWater=Math.max(maxWater,water);
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxWater;
    }

    public static void main(String[] args) {
        int []height = {1,8,6,2,5,4,8,3,7};
        System.out.println(maxArea(height));
    }
}
