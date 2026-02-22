package OnlinePlatform;
import java.util.List;
import java.util.ArrayList;
public class CountBinarySubstring696 {
    public static int countBinarySubstrings(String s) {
        List<Integer> groups = new ArrayList<>();
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                groups.add(count);
                count = 1;
            }
        }
        groups.add(count);
        int result = 0;
        for (int i = 1; i < groups.size(); i++) {
            result += Math.min(groups.get(i - 1), groups.get(i));
        }

        return result;
    }

    public static void main(String[] args) {
        String s = "00110011";
        System.out.println(countBinarySubstrings(s));

    }
}
