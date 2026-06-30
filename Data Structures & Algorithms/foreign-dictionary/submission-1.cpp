class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, -1);
        for (string& word : words) {
            for (char& ch : word) {
                int idx = ch - 'a';
                indeg[idx] = 0;
            }
        }
        string ans = "";
        for (int i = 1; i < words.size(); i++) {
            string s1 = words[i - 1], s2 = words[i];
            int m = s1.length(), n = s2.length(), j = 0;
            while (j < m && j < n && s1[j] == s2[j]) {
                j++;
            }
            if (j == n && m != n) return "";
            if (j == m) continue;
            adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            indeg[s2[j] - 'a']++;
        }
        queue<int> q;
        int ct = 0;
        for (int i = 0; i < 26; i++) {
            if (indeg[i] == 0) q.push(i);
            if (indeg[i] != -1) ct++;
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back('a' + node);
            for (auto neigh : adj[node]) {
                if (--indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        if (ans.length() != ct) return "";
        return ans;
    }
};
