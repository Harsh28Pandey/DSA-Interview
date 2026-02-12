package OnlinePlatform;

public class LongestPallindromicSustring {

    public static String longestPallindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.length(); i++) {

            // ODD length palindrome
            int left = i, right = i;
            while (left >= 0 && right < s.length()
                    && s.charAt(left) == s.charAt(right)) {

                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }

            // EVEN length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length()
                    && s.charAt(left) == s.charAt(right)) {

                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substring(start, start + maxLen);
    }

    public static void main(String[] args) {
        System.out.println(longestPallindrome("forgeeksskeegfor"));
    }
}
class Test{
    public static String checkPallindrome(String s){
        if(s.length()==0){
            return "";
        }
        int start=0;
        int maxLen=1;
        for(int i=0;i<s.length();i++){
            //for odd length
            int left=i;
            int right=i;
            while (left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
                int len=right-left+1;
                if(len>maxLen){
                    maxLen=len;
                    start=left;
                }
                left--;
                right++;
            }
            //for even length
            left=i;
            right=i+1;
            while (left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
                int len=right-left+1;
                if(len>maxLen){
                    maxLen=len;
                    start=left;
                }
                left--;
                right++;
            }
        }
        return s.substring(start,start+maxLen);
    }
}
