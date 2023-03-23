# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Solution
- Basic observation: the first root will be the first element in preorder traversal.
- Find its index in inorder traversal, then the left part will be the left subtree, and the right part will be the right subtree.
- Recursively build the left and right subtree with the same method.
## Complexity
- **Time Complexity**: `O(n ^ 2)`, where `n` is the number of nodes in the tree, for every single recursive call we use `O(n)` to get the index of the root in inorder traversal.
- **Space Complexity**:
    - `O(h)`, where `h` is the height of the tree for the recursive stack.
    - Aside: In the below code I use 2 vector to make it easily to use them this `O(n)`, but they can be removed and pass them by reference to the function and will be `O(h)` normally.

## Code
```cpp
class Solution {
public:
    int n; // number of nodes
    vector<int> inOrder, preOrder; // Used to Copy the preorder and inorder traversal of the tree

    int getInorderIdx(int val, int start, int end) { // Get the index of the value in the inorder traversal
        for (int i = start; i <= end; i++)
            if (inOrder[i] == val)
                return i;

        return -1;
    }

    TreeNode *build(int inStart, int inEnd, int preStart, int preEnd) {
        if (inStart > inEnd or preStart > preEnd) return nullptr; // No remaining nodes
        int rootVal = preOrder[preStart]; // The root will be the first value in the preorder traversal
        int rootIndexInorder = getInorderIdx(rootVal, inStart, inEnd); // Get the index of our root
        auto *root = new TreeNode(rootVal); // Create the root node
        int leftSubtreeSize = rootIndexInorder - inStart; // Get the size of the left subtree
        root->left = build(inStart, rootIndexInorder - 1, preStart + 1, preStart + leftSubtreeSize); // Build the left subtree
        root->right = build(rootIndexInorder + 1, inEnd, preStart + leftSubtreeSize + 1, preEnd); // Build the right subtree
        return root; // Return the root
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inOrder = inorder; // Copy the inorder traversal
        preOrder = preorder; // Copy the preorder traversal
        n = (int) inorder.size(); // Get the number of nodes
        return build(0, n - 1, 0, n - 1); // Build the tree
    }
};
```