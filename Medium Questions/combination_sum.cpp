// Problem - Combination Sum (39) - LeetCode

#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int> &arr, int index, int target, vector<vector<int>> &ans, vector<int> &combine) {
    if(index == arr.size() || target < 0) {
        return ;
    }
    if(target == 0) {
        if(s.find(combine) == s.end()) {
            ans.push_back(combine);
            s.insert(combine);
        }
        return ;
    }
    combine.push_back(arr[index]);
    getAllCombinations(arr,index + 1,target - arr[index],ans,combine); // single
    getAllCombinations(arr,index,target - arr[index],ans,combine); // multiple
    combine.pop_back(); // backtracking
    getAllCombinations(arr,index + 1,target,ans,combine); // exclusion
}

vector<vector<int>> combinationSum(vector<int> &arr, int target) {
    vector<vector<int>> ans;
    vector<int> combine;
    getAllCombinations(arr,0,target,ans,combine);
    return ans;
}

int main() {
    vector<int> arr = {2,3,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr,target);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}