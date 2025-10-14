package revision.patternpart1.com;

public class Butterflypattern {
    public static void butterfly(int n){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=i;k++){
                System.out.print("* ");
            }
            for(int j=2*(n-i);j>0;j--){
                System.out.print("  ");
            }
            for(int k=1;k<=i;k++){
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int i=n;i>=1;i--){
            for(int k=1;k<=i;k++){
                System.out.print("* ");
            }
            for(int j=2*(n-i);j>0;j--){
                System.out.print("  ");
            }
            for(int k=1;k<=i;k++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        butterfly(5);
    }
}
