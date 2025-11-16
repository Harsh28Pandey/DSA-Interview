package Divide.conquer.com;

public class Mergesort {
    public static void mergesort(int arr[],int lb,int ub){
        if(lb>=ub){
            return;
        }
        int mid=lb+(ub-lb)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,mid,lb,ub);
    }
    public static void merge(int arr[],int mid,int si,int ei){
        int temp[]=new int[ei-si+1];
        int i=si;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=ei){
            if(arr[i]>arr[j]){
                temp[k]=arr[j];
                j++;
            }else{
                temp[k]=arr[i];
                i++;
            }
            k++;
        }
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=ei){
            temp[k]=arr[j];
            k++;
            j++;
        }
        for(k=0 ,i=si;k< temp.length;i++,k++){
            arr[i]=temp[k];
        }
    }
    public static  void print(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }

    public static void main(String[] args) {
        int arr[]={1,4,5,6,3,2,7,5,3};
        mergesort(arr,0,arr.length-1);
        print(arr);
    }
}
