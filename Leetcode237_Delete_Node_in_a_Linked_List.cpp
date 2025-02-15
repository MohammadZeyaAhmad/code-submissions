/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/




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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        if(len==1 && n==1)
        {
            return NULL;
        }
        int k=len-n;
        temp=head;
        while(k)
        {
            if(n==1 && k==1)
            {
                break;
            }
            temp=temp->next;
            k--;
        }
        if(n==len)
        {
            ListNode* dummy=temp->next;
            temp->next=NULL;
            return dummy;

        }else if(n==1){
           temp->next=NULL;
           return head;
        }
         ListNode* dummy=temp->next;
         temp->val=temp->next->val;
         temp->next=dummy->next;
        return head;

    }
};
