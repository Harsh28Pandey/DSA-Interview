package OnlinePlatform;

import java.util.ArrayList;
import java.util.Arrays;

public class PlusOne66leetcode {
    public static int [] plusOne(int digits[], int n){
        StringBuilder str=new StringBuilder();
        for(int i=0;i<n;i++){
        str.append(digits[i]);
       }
         String str1= str.toString();
         int index=str.length();
        StringBuilder ans=new StringBuilder();
        int sum=0,carry=1;
       while (index!=0){
        sum=(str1.charAt(index-1)-'0')+carry;
        carry=sum/10;
        char c=(char) ('0'+sum%10);
        ans.append(c);
        index--;
    }
    if(carry!=0){
        ans.append('1');
    }
    String help=ans.reverse().toString();
    int arr[]=new int[help.length()];
    for(int i=0;i<help.length();i++){
    arr[i]=help.charAt(i)-'0';
    }

    return arr;
    }
    public static void main(String[] args) {
        int digits[] = {9,9,9,9};
        System.out.println(Arrays.toString(plusOne(digits, digits.length)));

    }
}
