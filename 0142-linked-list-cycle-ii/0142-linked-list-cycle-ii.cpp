/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;

        do{
            fast = fast->next->next;
            slow = slow->next;
        } while(fast != nullptr && fast->next != nullptr && fast != slow);

        if(fast != slow ) return nullptr;

        fast = head;

        while(fast != slow )
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};