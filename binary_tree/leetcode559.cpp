#include "../common.h"
//同样是利用层序遍历的思路
class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        queue<Node*> aux;
        if (!root) return 0;
        aux.push(root);
        while (!aux.empty()) {
            ++res;
            int size = aux.size();
            for (int i = 0; i < size; ++i) {
                Node* node = aux.front();
                aux.pop();
                for (int i = 0; i < node->children.size(); ++i) {
                    aux.push(node->children[i]);
                }
            }
        }
        return res;
    }
};