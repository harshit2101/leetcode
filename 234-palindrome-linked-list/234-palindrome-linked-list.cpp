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
    bool isPalindrome(ListNode* head) {
        stack<int> s;       int temp;
        if(head == nullptr || head -> next == nullptr)
            return true;
        ListNode *slow = head;
        while(head != nullptr){
            s.push(head -> val);
            head = head -> next;
        }
        while(slow != nullptr){
            if(s.top() != slow -> val){
                return false;
            }
            slow = slow -> next;
            s.pop();
        }
        return true;
    }
};