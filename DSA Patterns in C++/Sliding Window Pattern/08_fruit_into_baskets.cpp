// Problem - Fruit into Baskets (904) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0;
        int maxFruits = 0;

        for (int j = 0; j < fruits.size(); j++) {
            mp[fruits[j]]++;

            // Shrink window if more than 2 fruit types
            while (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }

            // Update maximum window size
            maxFruits = max(maxFruits, j - i + 1);
        }

        return maxFruits;
    }
};