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
    void mergeHelper(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr || root2 == nullptr) return;

        if(root1->left != nullptr && root2->left != nullptr){
            root1->left->val += root2->left->val;
            mergeHelper(root1->left, root2->left);
        }
        else if(root1->left == nullptr && root2->left != nullptr){
            TreeNode* newNode = new TreeNode(root2->left->val);
            root1->left = newNode;
            mergeHelper(root1->left, root2->left);
        }
        else if(root1->left != nullptr && root2->left == nullptr){
            mergeHelper(root1->left, root2->left);
        }


        if(root1->right != nullptr && root2->right != nullptr){
            root1->right->val += root2->right->val;
            mergeHelper(root1->right, root2->right);
        }
        
        else if(root1->right == nullptr && root2->right != nullptr){
            TreeNode* newNode = new TreeNode(root2->right->val);
            root1->right = newNode;
            mergeHelper(root1->right, root2->right);
        }
        else if(root1->right != nullptr && root2->right == nullptr){
            mergeHelper(root1->right, root2->right);
        }
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if(root1 == nullptr && root2 != nullptr) return root2;
        else if(root1 != nullptr && root2 == nullptr) return root1;
        else if (root1 ==nullptr && root2 == nullptr) return nullptr;
        root1->val += root2->val;
            
        mergeHelper(root1, root2);

        return root1;
        
    }
};