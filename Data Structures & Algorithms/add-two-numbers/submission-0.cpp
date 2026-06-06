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
         //initialize dummy node
        ListNode* dummyHead=new ListNode(-1);
        ListNode *curr=dummyHead;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        int carry=0;

        while(temp1!=NULL || temp2!=NULL){
            int sum=carry;
            if(temp1!=NULL) sum+=temp1->val;
            if(temp2!=NULL) sum+=temp2->val;

            ListNode *newNode=new ListNode(sum%10);
            carry=sum/10;

            curr->next = newNode;   // attach node
            curr = curr->next;      // move curr forward

            if(temp1!=NULL) temp1=temp1->next;
            if(temp2!=NULL) temp2=temp2->next;
        }

         //if there is a carry left at the end
        if(carry!=0){
            ListNode *newNode = new ListNode(carry);
            curr->next=newNode;
        }

        return dummyHead->next;
    }
};
