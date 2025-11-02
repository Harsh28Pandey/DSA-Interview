#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &ans, int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && ans[left] > ans[largest])
        largest = left;

    if (right < n && ans[right] > ans[largest])
        largest = right;

    if (largest != index) {
        swap(ans[largest], ans[index]);
        heapify(ans, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> ans;

    for (int i = 0; i < n; i++)
        ans.push_back(a[i]);

    for (int i = 0; i < m; i++)
        ans.push_back(b[i]);

    // convert combined array into a max heap
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, i, size);
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter size of first heap: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of first heap: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second heap: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of second heap: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> mergedHeap = mergeHeaps(a, b, n, m);

    cout << "Merged Max Heap: ";
    for (int i = 0; i < mergedHeap.size(); i++) {
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    return 0;
}