package OnlinePlatform;
// this rum for few test cases due to some logical error in the code
public class AddBinary {
    public static String binaryString(String a,String b){
        int index1=a.length();
        int index2=b.length();
//        int n=Math.max();
        int sum=0,carry=0;
        StringBuilder sb=new StringBuilder();
        while(index2!=0){
            sum=(a.charAt(index1-1)-'0')+(b.charAt(index2-1)-'0')+carry;
            if(sum==2){
                sb.append('0');
                carry=1;
                sum=0;
            }else if (sum==3){
                sb.append('1');
                carry=1;
                sum=0;
            }
            else{
                char c=(char)(sum+'0');
                sb.append(c);
                sum=0;
                carry=0;
            }
            index1--;index2--;
        }
        while (index1!=0){
            sum=a.charAt(index1-1)-'0'+carry;
            if(sum==2){
                sb.append('0');
                carry=1;
                sum=0;
            }
            else{
                char c=(char)(sum+'0');
                sb.append(c);
                sum=0;
                carry=0;
            }
            index1--;
        }
        while (index2!=0){
            sum=b.charAt(index2-1)-'0'+carry;
            if(sum==2){
                sb.append('0');
                carry=1;
                sum=0;
            }
            else{
                char c=(char)(sum+'0');
                sb.append(c);
                sum=0;
                carry=0;
            }
            index2--;
        }
        if(carry!=0){
            sb.append('1');
        }
         sb.reverse();
        return sb.toString();
    }

    public static void main(String[] args) {
        String a="1";
        String b="111";
        System.out.println(binaryString(a,b));
    }
}
