/* Given the head of a linked list, rotate the list to the right by k places.*/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        k=k>=len?((k-len)%len):k;
        int pos=k>0?(len-k-1):0;
        if(pos!=0)
        {
        temp=head;
        while(pos>=1 && temp)
        {
          temp=temp->next;
          pos--;
        }
        ListNode *new_head=temp->next;
        temp->next=NULL;
     
        ListNode* dummy=new_head;
        while(dummy->next)
        {
            dummy=dummy->next;
        }
        dummy->next=head;
        return new_head;
        }
        return head;
    }
};
