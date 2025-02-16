/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.*/

/** 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head; // If the list is empty or has only one node, return as is

        ListNode* odd = head; // Initialize odd pointer to the head of the list
        ListNode* even = head->next; // Initialize even pointer to the second node
        ListNode* temp = even; // Store the start of the even list

        while (even != nullptr && even->next != nullptr) {
            // Update odd and even pointers to skip one node each
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        // Connect the end of the odd list to the start of the even list
        odd->next = temp;

        return head; // Return the modified list
    }
};
