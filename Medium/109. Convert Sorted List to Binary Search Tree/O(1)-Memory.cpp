class Solution {
public:

    TreeNode *buildTree(ListNode*start, ListNode*end) {
        auto *slow = start, *fast = start; // Find the middle element
        if(start == end) return nullptr;

        while(fast != end and fast->next != end) { // Go to the middle point
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *root = new TreeNode(slow->val); // Create the root with the middle value
        root->left = buildTree(start, slow); // Build the left subtree
        root->right = buildTree(slow->next, end); // Build the right subtree
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr); // Return the root node of the BST
    }
};