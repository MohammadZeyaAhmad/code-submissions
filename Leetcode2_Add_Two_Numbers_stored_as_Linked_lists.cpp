/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev=NULL;
         ListNode* head=NULL;
        int carry=0;
        while(l1 || l2)
        {
                ListNode *curr=new ListNode();
                if(l1 && l2){
                  int digit=l1->val+l2->val+carry;
                   if(digit>=10){
                       curr->val=digit%10;
                       carry=digit/10;
                   }else{
                      curr->val=digit%10;
                       carry=0;
                   }
                }else if(l1){
                    int digit=l1->val+carry;
                   if(digit>=10){
                       curr->val=digit%10;
                       carry=digit/10;
                   }else{
                      curr->val=digit%10;
                       carry=0;
                   }
                }else
                {
                    int digit=l2->val+carry;
                   if(digit>=10){
                       curr->val=digit%10;
                       carry=digit/10;
                   }else{
                      curr->val=digit%10;
                       carry=0;
                   }
                }
               
                if(prev==NULL)
                {
                    prev=curr;
                    curr->next=NULL;
                    head=curr;
                }else
                {
                    prev->next=curr;
                    prev=curr;
                }
                l1=l1?l1->next?l1->next:NULL:NULL;
                l2=l2?l2->next?l2->next:NULL:NULL;
        }

        if(carry!=0)
        {
              ListNode *curr=new ListNode(carry);
              prev->next=curr;
        }

        return head;
    
        
    }
};
