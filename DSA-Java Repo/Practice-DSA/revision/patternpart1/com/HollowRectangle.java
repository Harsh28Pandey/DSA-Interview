package revision.patternpart1.com;

public class HollowRectangle {
    public static void PrintRectangle(int length,int width){
        for(int i=1;i<width;i++){
            for(int j=1;j<length;j++){
                if(i==1){
                    if(j==1){
                        System.out.print("* ");
                    }else {
                        System.out.print(" * ");
                    }
                }else if (j == 1 || j == length - 1) {
                        System.out.print("*  ");
                }else if(i==width-1){
                        System.out.print("*  ");
                    }else{
                    System.out.print("   ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        PrintRectangle(8,6);
    }
}
