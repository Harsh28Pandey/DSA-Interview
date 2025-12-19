package SimpleArrayProblem;

public class MissingElement {
    public static int missing(int arr[]){
        int n=arr.length;
        long  totalSum=(long)(n+1)*(n+2)/2;
        long arrSum=0;
        for(int i:arr){
            arrSum+=i;
        }
        return (int)(totalSum-arrSum);
    }

    public static void main(String[] args) {
        int arr[] = {1};
        System.out.println(missing(arr));
    }
}
