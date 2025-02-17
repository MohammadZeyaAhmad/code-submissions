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
        ListNode  *pivot=NULL;
        ListNode  *pivot_head=NULL;
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
            }else if(head->val>x)
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
            }else
            {
                if(!pivot)
               {
                 pivot=temp;
                 pivot_head=temp;
               }else
               {
                  pivot->next=temp;
                  pivot=temp;
               }
            }
            head=head->next;
        }

        if(pivot)
        {
          left->next=pivot_head;
          pivot->next=right_head;
        }else
        {
           left->next=right_head;
        }

        return left_head;
        
        
    }
};
