class Solution {
public:
    struct TrieNode {
        TrieNode* next[2];
        int count;
        TrieNode() {
            next[0] = next[1] = NULL;
            count = 0;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(int n) {
        TrieNode* cur = root;
        for (int i = 15; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (!cur->next[bit]) cur->next[bit] = new TrieNode();
            cur = cur->next[bit];
            cur->count++;
        }
    }

    int query(int x, int k) {
        TrieNode* cur = root;
        int res = 0;

        for (int i = 15; i >= 0; i--) {
            if (!cur) break;

            int xbit = (x >> i) & 1;
            int kbit = (k >> i) & 1;

            if (kbit == 1) {
                // count subtree where XOR bit = 0 => ybit = xbit
                if (cur->next[xbit])
                    res += cur->next[xbit]->count;

                // continue where XOR bit = 1 => ybit = !xbit
                cur = cur->next[xbit ^ 1];
            } else {
                // XOR bit must be 0 => ybit = xbit
                cur = cur->next[xbit];
            }
        }

        return res;
    }

    int cntPairs(vector<int>& arr, int k) {
        int ans = 0;
        for (int x : arr) {
            ans += query(x, k);
            insert(x);
        }
        return ans;
    }
};
