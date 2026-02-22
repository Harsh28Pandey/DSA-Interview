package OnlinePlatform;

public class BestTimetobuyandSellstocks {
    public static int maxProfit(int prices[]){
        int buy1=prices[0];
        int buy2=prices[0];
        int firstProfit=0;
        int secondProfit=0;
        for(int i=0;i<prices.length;i++){
           if(buy1>prices[i]){
               buy1=prices[i];
           }else if(prices[i]-buy1>firstProfit){
               firstProfit=prices[i]-buy1;
           }
           if(buy2>prices[i]-firstProfit){
               buy2=prices[i]-firstProfit;
           }else if(prices[i]-buy2>secondProfit){
               secondProfit=prices[i]-buy2;
           }
        }
        return secondProfit;
    }

    public static void main(String[] args) {
        int []prices={3,3,5,0,0,3,1,4};
        System.out.println(maxProfit(prices));
    }
}
