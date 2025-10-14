package revision.patternpart1.com;

public class HollowRohmbus {
    public static void Rohmbus(int n){
        for(int i=1;i<=n;i++){
            for(int j=n-i;j>0;j--){
                System.out.print(" ");
            }
            for(int k=1;k<=n;k++){
                if(i==1 || i==n ||k==1 || k==n) {
                    System.out.print(" * ");
                }else{
                     System.out.print("   ");
                }
            }
            System.out.println();
        }

    }
    public static void main(String[] args) {
        Rohmbus(5);
    }
}
