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
    ListNode* removeNthFromEnd(ListNode* head, int k) {

        int n =0;
        ListNode* temp = head;
        
        while(temp!=nullptr)
        {
            n++;
            temp = temp->next;
        }
        if(k == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int target  = n-k-1;
        temp = head;
        while(target--)
        {
            temp = temp ->next;
        }
        temp->next  = temp->next->next;
        return head;
        
    }
};
