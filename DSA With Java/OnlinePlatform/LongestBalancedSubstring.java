package OnlinePlatform;

import java.util.Stack;

public class LongestBalancedSubstring {
    public static String subset(String str, int i,String newStr,String res) {
        if (i == str.length()) {
            if (isValid(newStr)&&newStr.length() > res.length()) {
                return newStr;
            }
            return res;
        }

        String include = subset(str, i + 1, newStr + str.charAt(i), res);
        String exclude = subset(str, i + 1, newStr, res);

        return include.length() > exclude.length() ? include : exclude;
    }
    public static boolean isValid(String s){
        if(s.length()==0){
            return false;
        }
        int freq[]=new int[3];
        for(int i=0;i<s.length();i++){
            freq[s.charAt(i)-'a']++;
        }
        int count=0;
        for(int f:freq){
            if(f>0){
               if(count==0) {
                   count=f;
               }else if(count!=f){
                   return false;
               }
            }
        }
        return true;
    }
    public static int longestBalancedSubstring1(String s) {

        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {

            int[] freq = new int[3];

            for (int j = i; j < n; j++) {

                char ch = s.charAt(j);
                freq[ch - 'a']++;

                if (isBalanced(freq)) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }

    public static boolean isBalanced(int[] freq) {

        int count = 0;

        for (int f : freq) {
            if (f > 0) {
                if (count == 0) {
                    count = f;
                } else if (count != f) {
                    return false;
                }
            }
        }

        return true;
    }


    public static void main(String[] args) {
    String str="aabcc";
        System.out.println(longestBalancedSubstring1(str));
}
}
