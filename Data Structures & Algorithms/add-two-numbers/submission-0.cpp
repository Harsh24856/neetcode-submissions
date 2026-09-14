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
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(curr1 && curr2){
            int p1=curr1->val,p2=curr2->val;
            int ans=p1+p2+carry;
            carry=ans/10;
            ans=ans%10;
            ListNode* newNode=new ListNode(ans);
            curr->next=newNode;
            curr=curr->next;
            curr1=curr1->next;curr2=curr2->next;
        }
        while(curr1){
            int p1=curr1->val;
            int ans=p1+carry;
            carry=ans/10;
            ans=ans%10;
            ListNode* newNode=new ListNode(ans);
            curr->next=newNode;
            curr=curr->next;curr1=curr1->next;
        }
         while(curr2){
            int p1=curr2->val;
            int ans=p1+carry;
            carry=ans/10;
            ans=ans%10;
            ListNode* newNode=new ListNode(ans);
            curr->next=newNode;
            curr=curr->next;curr2=curr2->next;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
        }
        return dummy->next;
    }
};