// Time Complexity - O(n)
// Space Complexity - O(1)

void sortTwoColors(vector<int> arr) {
    int i = 0;
    int j = arr.size() - 1;

    while(i < j) {
        if(arr[i] == 0) {
            i = i + 1;
        }
        else {
            swap(arr[i],arr[j]);
        }
    }
}