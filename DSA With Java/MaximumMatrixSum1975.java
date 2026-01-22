package OnlinePlatform;

public class MaximumMatrixSum1975 {
    // for maximum matrix sum we add all absolute values
    // (absolute values are values =|-values|) so first we add all matrix values by
    // making it positive if negative value in this is event count then total sum
    // is sum of all matrix element by ignoring negativ sign if negative count is odd
    // the we have to find minimum absolute value and minus it from totalsum=2*minAbs
    // 2 is ultiplied becuse we have add this value as positive so one time
    // minus to nullify that value and one minus for decreasing that value from totalsum
    public static int maxMatrixSum(int [][]matrix){
        int row=matrix.length;
        int col=matrix[0].length;
        int totalSum=0;
        int negCount=0;
        int minAbs=Integer.MAX_VALUE;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]<0){
                    matrix[i][j]=-(matrix[i][j]);
                    totalSum+=(matrix[i][j]);
                    negCount++;
                }else {
                    totalSum += matrix[i][j];
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                minAbs=Math.min(matrix[i][j],minAbs);
            }
        }
        if(negCount%2==1){
            totalSum=totalSum-(2*minAbs);
        }
        return totalSum;
       }

    public static void main(String[] args) {
        int matrix[][]={{1,-1},{-1,1}};
        System.out.println(maxMatrixSum(matrix));
    }
}
