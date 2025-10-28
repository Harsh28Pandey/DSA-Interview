package Array2D.com;

public class DiagonalSum {
    // brute force approach
    public static void matrixsumDiagonal(int mat[][]){
        int sum=0;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(i==j){
                  sum+=mat[i][j];
                }
                if(i+j==mat.length-1){
                    sum+=mat[i][j];
                }
            }
        }
        System.out.println(sum);
    }
   //optimized approach
    public static int matsumDiagonal(int mat[][]){
        int sum=0;
        for(int i=0;i<mat.length;i++){
            sum+=mat[i][i];
            if(i!=mat.length-i-1){
                sum+=mat[i][mat.length-i-1];
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        int arr[][]={{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};
        //brute force approach
        matrixsumDiagonal(arr);
    //optimized approach
        System.out.println(matsumDiagonal(arr));
    }
}
