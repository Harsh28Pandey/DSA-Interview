// Problem - Contaimer With Most Water (11) - Leetcode

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> &height) {
    int maxWater = 0;
    int left = 0, right = height.size() - 1;
    while(left < right) {
        int weight = right - left;
        int minHeight = min(height[left], height[right]);
        int currentWater = weight * minHeight;
        maxWater = max(maxWater, currentWater);
        height[left] < height[right] ? left++ : right--;
    }
    return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = maxArea(height);
    cout << "The maximum area of water that can be contained is: " << result << endl;
    return 0;
}