package OnlinePlatform;
import java.util.ArrayList;
import java.util.List;


public class BinaryWatch401 {
    public List<String> readBinaryWatch(int turnedOn){
        List<String> res=new ArrayList<>();
        for(int hour=0;hour<12;hour++){
            for(int minute=0;minute<60;minute++){
                if(Integer.bitCount(hour)+Integer.bitCount(minute)==turnedOn){
                    res.add(String.format("%d:%02d",hour,minute));
                }
            }
        }
        return res;
    }
    public static void main(String [] args){
        BinaryWatch401 bw=new BinaryWatch401();
        System.out.println(bw.readBinaryWatch(2));
    }
}
