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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* final = new  ListNode(0);
        ListNode* temp  = final;
        ListNode* i = list1;
        ListNode* j = list2;

        while(i!= nullptr && j!=nullptr)
        {
            if(i->val<j->val)
            {
                temp->next = i;
                temp = temp->next;
                i = i->next;
            }
            else if(j->val < i->val )
            {
                temp->next = j;
                temp = temp->next;
                j = j->next;
            }
            else{
                temp->next = j;
                temp = temp->next;
                j = j->next;               
            }
        }

        if(i!=nullptr)
        {
            temp->next = i;
        }else{
            temp->next = j;
        }

        return final->next;
    }
};
