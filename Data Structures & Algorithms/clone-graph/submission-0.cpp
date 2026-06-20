/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        // If already cloned, return the clone
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create clone of current node
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone all neighbors
        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(dfs(neigh));
        }

        return clone;
    }


    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        return dfs(node);
    }
};
