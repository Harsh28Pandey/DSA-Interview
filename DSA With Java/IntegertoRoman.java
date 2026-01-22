package OnlinePlatform;

import java.util.HashMap;

public class IntegertoRoman {
    public static String  inttoroman(int num){
        String [] roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        StringBuilder sb=new StringBuilder();
        for(int i=0;i< values.length;i++){
            while(num>=values[i]){
                sb.append(roman[i]);
                num-=values[i];
            }
        }
        return sb.toString();
    }
   public static int romantoint(String num){
       int total=0;
       int prev=0;
       HashMap<Character,Integer>map=new HashMap<>();
       map.put('I', 1);
       map.put('V', 5);
       map.put('X', 10);
       map.put('L', 50);
       map.put('C', 100);
       map.put('D', 500);
       map.put('M', 1000);
       for(char c:num.toCharArray()){
           int curr=map.get(c);
           if(curr>=prev){
               total=total-2*prev+curr;
           }else{
               total+=curr;
           }
           prev=curr;
       }
       return total;
   }
   public static int helpRoman(char c){
        switch (c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return -1;
   }
   public static int romantointeger(String s){
        int index=0;
        int total=0;
        while(index<s.length()-1){
            if(helpRoman(s.charAt(index))<helpRoman(s.charAt(index+1))){
                total-=helpRoman(s.charAt(index));
            }else{
                total+=helpRoman(s.charAt(index));
            }
            index++;
        }
        total+=helpRoman(s.charAt(index));
        return total;
   }
    public static void main(String[] args) {
        System.out.println(inttoroman(3749));
        System.out.println(romantoint("III"));
        System.out.println(romantointeger("III"));
    }
}
