package OnlinePlatform;

import java.util.ArrayList;
import java.util.Collections;

public class ReverseBits {
    public static int reverseBits(int n){
        int result = 0;

        for (int i = 0; i < 32; i++) {
            result <<= 1;        // shift result left
            result |= (n & 1);   // add last bit of n
            n >>>= 1;            // unsigned right shift
        }

        return result;
    }
  public static void bit(int n){
StringBuilder result =new StringBuilder("");

//      while (n > 0) {
//           result.append((n & 1));
//          n = n >> 1;
//      }

      for(int i=0;i<32;i++){
          result.append((n & 1));
          n = n >>1;
      }


      System.out.println(result.reverse());
  }
    public static void main(String[] args) {
        System.out.println(reverseBits(8));
        bit(8);
    }
}
