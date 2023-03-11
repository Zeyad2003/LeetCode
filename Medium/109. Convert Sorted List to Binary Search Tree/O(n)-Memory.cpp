class Solution {
public:
    vector<int> store; // Store linked list values

    TreeNode *buildTree(int start, int end) {
        if(start > end) return nullptr;

        int mid = (start + end) / 2; // Get the middle element
        auto *root = new TreeNode(store[mid]); // Make the middle element the root
        auto *left = buildTree(start, mid - 1); // Recursively build the left subtree with the same logic
        auto *right = buildTree(mid + 1, end); // Recursively build the right subtree with the same logic
        root->left = left; root->right = right; // Connect the left and right subtrees to the root
        return root; // Return the root node
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head) { // Add values to the store vector
            store.emplace_back(head->val);
            head = head->next;
        }

        return buildTree(0, (int) store.size() - 1); // Return the root node of the BST
    }
};