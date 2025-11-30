package OnlinePlatform;

import java.util.*;

public class MmergeSimilarItems {
    public static List<List<Integer>> merge(int [][]item1, int [][] item2) {
        int n = item1.length;
        int m = item2.length;

        HashSet<Integer>set =new HashSet<>();

        for(int i=0;i<n;i++){
            set.add(item1[i][0]);
        }
        for(int i=0;i<m;i++){
            set.add(item2[i][0]);
        }
        System.out.println(set);
        int p = set.size();
        int temp[][] = new int[p][2];
        int i,j;
        int k=0;
        for ( i = 0; i < n; i++) {
            for ( j = 0; j < m; j++) {
                if (item1[i][0] == item2[j][0]) {
                    temp[k][0] = item1[i][0];
                    temp[k][1] = item1[i][1] + item2[j][1];
                    k++;
                }
            }
            }
         ArrayList<Integer> list = new ArrayList<>(set);
        for (i = 0; i < m; i++) {
            int key = item2[i][0];
            boolean exists = false;

            for (int t = 0; t < k; t++) {
                if (temp[t][0] == key) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                temp[k][0] = key;
                temp[k][1] = item2[i][1];
                k++;
            }
        }




        for ( i = 0; i < temp.length; i++) {
                for ( j = 0; j < temp[0].length; j++) {
                    System.out.println(temp[i][j]);
                }
                System.out.print("\n");
            }
            Arrays.sort(temp, Comparator.comparingInt(o -> o[0]));
            List<List<Integer>> ret = new ArrayList<>();
            for ( i = 0; i < temp.length; i++) {
                ArrayList<Integer> row = new ArrayList<>();
                for ( j = 0; j < temp[i].length; j++) {
                    row.add(temp[i][j]);
                }
                ret.add(row);
            }

            System.out.println(ret);
            return ret;
        }

    public static void main(String[] args) {
//       int  items1[][] = {{1,1},{4,5},{3,8}};
//       int items2[][] = {{3,1},{1,5}};
//        int  items1[][] = {{1,1},{3,2},{2,3}};
//        int items2[][] = {{2,1},{3,2},{1,3}};
        int [][]items1 = {{1,3},{2,2}};
        int [][]items2 = {{7,1},{2,2},{1,4}};
        merge(items1,items2);
    }
}

