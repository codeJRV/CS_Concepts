/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int counter;
int kthVal;

class Solution {
public:
    

    
    int kthSmallest(TreeNode* root, int k) {
        
                     counter = 0; 
                     kthVal = 0;
                     Inorder(root, k);
                     return kthVal;
    }
    
    void Inorder(TreeNode* node,int k)
    {
        if(!node) return;
        
        Inorder(node->left, k);
        
        counter++;
        
        if(counter == k)
           {
               kthVal = node->val;
               return;
           }
        
        Inorder(node->right, k);
        
        
    }
    

    
};