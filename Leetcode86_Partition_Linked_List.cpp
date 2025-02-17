/* Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.*/

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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *left=NULL;
        ListNode *left_head=NULL;
        ListNode *right=NULL;
        ListNode *right_head=NULL;
        while(head)
        {
            ListNode *temp=new ListNode(head->val);
            if(head->val<x)
            {
               if(!left)
               {
                 left=temp;
                 left_head=temp;
               }else
               {
                  left->next=temp;
                  left=left->next;
               }
            }else
            {
                 if(!right)
               {
                 right=temp;
                 right_head=temp;
               }else
               {
                  right->next=temp;
                  right=right->next;
               }
            }
            head=head->next;
        }
   
        if(left_head && right_head)
        {
          left->next=right_head;
          return left_head;
        }

        return !left_head?right_head:left_head;
        
    }
};
