// Problem - Minimum Number of Coins - gfg
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
  public:
    int findMin(int n) {
        // code here
        int currency[] = {2000,500,200,100,50,20,10,5,2,1};
        int notes = 0;
        int i = 0;
        vector<int> ans;
        
        while(n) {
            notes = n / currency[i];
            while(notes--) {
                ans.push_back(currency[i]);
            }
            n % currency[i];
            i++;
        }
        return ans;
    }
};