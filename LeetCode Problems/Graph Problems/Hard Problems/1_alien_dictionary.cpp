// Problem - Alien Dictionary - gfg

class Solution {
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        vector<int> inDeg(K,0);

        for(int i = 0; i < N - 1; i++) {
            strinf str1 = dict[i], str2 = dict[i + 1];
            int j = 0; // starting index of str1
            int k = 0; // starting index of str2

            while(j < str1.size() && k < str2.size() && str1[j] == str2[k]) {
                j++;
                k++;
            }

            if(j == str1.size())
            continue;

            adj[str1[j] - 'a'].push_back(str2[k] - 'a');
            inDeg[str2[k] - 'a']++;
        }

        queue<int> q;
        for(int i = 0; i < K; i++) {
            if(inDeg[i] == 0)
            q.push(i);
        }

        string ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            char c = 'a' + node;
            ans += c;

            for(int i = 0; i < adj[node].size(); i++) {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]] == 0)
                q.push(adj[node][i]);
            }
        }
        return ans;
    }
}