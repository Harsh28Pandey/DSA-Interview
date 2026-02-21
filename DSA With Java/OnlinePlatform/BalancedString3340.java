package OnlinePlatform;

public class BalancedString3340 {
    public static boolean isBalnced(String num){
        int evenSum=0;
        int oddSum=0;

        for(int i=0;i<num.length();i++){
            if((i+1)%2==0){
                evenSum+=num.charAt(i)-'0';
            }
            else{
                oddSum+=num.charAt(i)-'0';
            }
        }
        if(oddSum==evenSum){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(isBalnced("24123"));
    }
}
