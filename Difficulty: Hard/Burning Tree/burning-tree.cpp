class Solution {
public:
    void buildGraph(Node* root,
                    unordered_map<Node*, vector<Node*>>& omap,
                    Node* parent,
                    Node*& targetNode,
                    int target) {
        
        if (!root) return;

        if (root->data == target) {
            targetNode = root;
        }

        if (parent) {
            omap[root].push_back(parent);
            omap[parent].push_back(root);
        }

        buildGraph(root->left, omap, root, targetNode, target);
        buildGraph(root->right, omap, root, targetNode, target);
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, vector<Node*>> omap;
        Node* targetNode = NULL;

        buildGraph(root, omap, NULL, targetNode, target);

        if (!targetNode) return 0; // safety

        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = -1;

        while (!q.empty()) {
            int size = q.size();
            time++;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                for (auto neighbor : omap[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        return time;
    }
};