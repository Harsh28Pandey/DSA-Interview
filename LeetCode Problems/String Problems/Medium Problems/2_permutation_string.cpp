// Problem - Permutation in String (567) - LeetCode

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]) {
    for(int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};
    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }
    int windowSize = s1.length();
    for(int i = 0; i < s2.length(); i++) {
        int windowIndex = 0, index = i;
        int windowFreq[26] = {0};

        while(windowIndex < windowSize && index < s2.length()) {
            windowFreq[s2[index] - 'a']++;
            windowIndex++;
            index++;
        }

        if(isFreqSame(freq, windowFreq)) { // found
            return true;
        }
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    if(checkInclusion(s1, s2)) {
        cout << "Permutation exists in the string." << endl; // Output: true
    } else {
        cout << "Permutation does not exist in the string." << endl;
    }
    return 0;
}