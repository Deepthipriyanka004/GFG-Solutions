class Solution {
  public:
    bool findPath(Node* root, int target, vector<char>& path) {
        if (!root) return false;

        if (root->data == target)
            return true;

        // Try left
        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        // Try right
        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q) {
        vector<char> pathP, pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        // Find common prefix = path to LCA
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        // Directions from LCA to p and q
        vector<char> path;

        // p -> LCA: reverse directions
        for (int j = (int)pathP.size() - 1; j >= i; j--)
            path.push_back(pathP[j]);

        // LCA -> q
        for (int j = i; j < pathQ.size(); j++)
            path.push_back(pathQ[j]);

        // No movement means p == q (usually not applicable)
        if (path.size() <= 1)
            return -1;

        int turns = 0;

        for (int j = 1; j < path.size(); j++) {
            if (path[j] != path[j - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};