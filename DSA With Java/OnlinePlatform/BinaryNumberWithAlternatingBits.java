package OnlinePlatform;

public class BinaryNumberWithAlternatingBits {
    public static boolean hasAlternatingBits(int n) {
      StringBuilder str=new StringBuilder("");
      int result;
      while(n!=0){
          str.append(n&1);
          n=n>>1;
      }
      String res=str.reverse().toString();
      for(int i=0;i<str.length()-1;i++){
          if(str.charAt(i)==str.charAt(i+1)){
              return false;
          }
      }
      return true;
    }
//optimize
    public static boolean hasAlternatingbits(int n){
        String str=Integer.toBinaryString(n);
        System.out.println(str);
        for(int i=0;i<str.length()-1;i++){
            if(str.charAt(i)==str.charAt(i+1)){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
//        System.out.println(hasAlternatingBits(7));
        System.out.println(hasAlternatingbits(7));
    }
}
