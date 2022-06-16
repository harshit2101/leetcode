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
        ListNode* left=new ListNode(0);
        ListNode* right=new ListNode(0);
        ListNode* lhead=left;
        ListNode* rhead=right;
        
        while(head){
            if(head->val<x){
                lhead->next=head;
                lhead=lhead->next;
            }
            else{
                rhead->next=head;
                rhead=rhead->next;
            }
            head=head->next;
        }
        
        rhead->next=NULL;
        lhead->next=right->next;
        head=left->next;
        delete left,right;
        return head;
    }
};