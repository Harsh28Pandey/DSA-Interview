// Problem - Trapping Rain Water (42) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;
    int index = 0;
    int left_max = 0, right_max = 0, max_height = height[0];

    //max height og building
    for(int i = 1; i < n; i ++)
    {
        if(max_height < height[i])
        {
            max_height = height[i];
            index = i;
        }
    }

    //left part
    for(int i = 0; i < index; i ++)
    {
        if(left_max > height[i])
        water += left_max - height[i];
        else
        left_max = height[i];
    }

    //right part
    for(int i = n - 1; i > index; i --)
    {
        if(right_max > height[i])
        water += right_max - height[i];
        else
        right_max = height[i];
    }
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height);
    cout << "Trapped rain water: " << result << endl; // Output: 6
    return 0;
}