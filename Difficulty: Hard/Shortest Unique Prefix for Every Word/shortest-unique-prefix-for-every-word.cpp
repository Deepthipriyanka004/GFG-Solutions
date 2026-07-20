class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        int freq;

        TrieNode() {
            freq = 0;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
            node->freq++;
        }
    }

    string getPrefix(string &word) {
        TrieNode* node = root;
        string ans = "";

        for (char c : word) {
            int idx = c - 'a';
            node = node->child[idx];
            ans += c;
            if (node->freq == 1)
                break;
        }

        return ans;
    }

    vector<string> findPrefixes(vector<string>& arr) {
        for (auto &word : arr)
            insert(word);

        vector<string> res;
        for (auto &word : arr)
            res.push_back(getPrefix(word));

        return res;
    }
};