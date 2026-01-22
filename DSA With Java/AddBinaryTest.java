package OnlinePlatform;

public class AddBinaryTest {
    public static String BinaryAdd(String a,String b){
        int index1=a.length();
        int index2=b.length();
        int sum=0;int carry=0;
        StringBuilder sb=new StringBuilder();
        while(index2!=0 && index1!=0){
            sum=(a.charAt(index1-1)-'0')+(b.charAt(index2-1)-'0')+carry;
            carry=sum/2;
            char c=(char)('0'+sum%2);
            sb.append(c);
            index1--;index2--;
        }
        while(index1!=0){
            sum=(a.charAt(index1-1)-'0')+carry;
            carry=sum/2;
            char c=(char)('0'+sum%2);
            sb.append(c);
            index1--;
        }
        while(index2!=0){
            sum=(b.charAt(index2-1)-'0')+carry;
            carry=sum/2;
            char c=(char)('0'+sum%2);
            sb.append(c);
            index2--;
        }
        if(carry!=0){
            sb.append('1');
        }
        sb.reverse();
//        while(sb.length() > 1 && sb.charAt(0) == '0') {
//            sb.deleteCharAt(0);
//        } this case basically used when we do not need leeding zeros in our output i used it because without using
//        it it gives error in gfg but we know that lesading zeros have doesn't mean without writing the code run in
//        leetcode

        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(BinaryAdd("1","111"));
    }
}
