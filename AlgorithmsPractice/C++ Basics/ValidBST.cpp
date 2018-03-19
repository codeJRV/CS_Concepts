#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    bool isValidBST(TreeNode* root) {      
        return valid(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }

    bool valid(TreeNode* node, long minVal, long maxVal) {                          /// key is to use long instead of int in order to prevent integer overflow 
        if(!node ) {
            return true;
        }

        if((node->val <= minVal || node->val >= maxVal)) {
            return false;
        }

        return valid(node->left, minVal, node->val) &&
        valid(node->right, node->val, maxVal);
    }


int main()
{
    TreeNode *t = new TreeNode(2147483647);
//    t->right = new TreeNode(3);
//    t->left = new TreeNode(1);
    bool ret = isValidBST(t);
    if (ret)
        cout << "yaaagoo";
    else
        cout<<"Nahiii";

    return 0;
}