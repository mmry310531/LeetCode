/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<double> ans;
    unordered_map<int, double> containerDepthVal;
    unordered_map<int, int> containerDepthCnt;

    void depthMiner(TreeNode* node, int depth){
        if(node == nullptr)
            return;

        containerDepthVal[depth] += node->val;
        containerDepthCnt[depth]++;
        depthMiner(node->left, (depth+1));
        depthMiner(node->right, (depth+1));

        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        depthMiner(root, 0);
        
        // count
        for(int i=0;i<containerDepthCnt.size();i++){
            ans.push_back(containerDepthVal[i] / (float)containerDepthCnt[i]);
        }
        return ans;
    }
};