// Problem - string Compression (443) - LeetCode

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compress(vector<char> &chars) {
    int n = chars.size();
    int index = 0;
    for(int i = 0; i < n; i++) {
        char ch = chars[i];
        int count = 0;
        while(i < n && chars[i] == ch) {
            count++;
            i++;
        }
        if(count == 1) {
            chars[index++] = ch;
        } else {
            chars[index++] = ch;
            string str = to_string(count);
            for(char dig : str) {
                chars[index++] = dig;
            }
        }
        i--; // Adjust for the last increment in the while loop
    }
    chars.resize(index); // Resize the vector to the new length
    return index; // Return the new length of the compressed string
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);
    cout << "Compressed Length: " << newLength << endl; // Output: 6
    cout << "Compressed String: ";
    for(int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl; // Output: "a2b2c3"
    return 0;
}