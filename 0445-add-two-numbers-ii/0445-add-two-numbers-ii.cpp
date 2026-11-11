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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next = NULL;
        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* addition(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL){
            return (l1==NULL)?(l2):(l1);
        }
        ListNode* temp = NULL;
        ListNode* ans = NULL;
    
        int carry,sum=0,r;
        while(l1 != NULL && l2 != NULL){
            carry = sum/10;
            sum = l1->val + l2->val + carry;
            r = sum%10;
            ListNode* newNode = new ListNode(r);
            if(ans == NULL){
                ans = newNode;
                temp = ans;
                l1=l1->next;
                l2=l2->next;                
            }
            else{
                temp->next = newNode;
                temp = newNode;
                l1=l1->next;
                l2=l2->next;  
            }            
        }
        while(l1 != NULL){
            carry = sum/10;
            sum = l1->val + carry;
            r = sum%10;
            ListNode* newNode = new ListNode(r);
            temp->next = newNode;
            temp = newNode;
            l1 = l1->next;
        }
        while(l2 != NULL){
            carry = sum/10;
            sum = l2->val + carry;
            r = sum%10;
            ListNode* newNode = new ListNode(r);
            temp->next = newNode;
            temp = newNode;
            l2 = l2->next;
        }
        carry = sum/10;
        while(carry>0){
            r = carry%10;
            ListNode* newNode = new ListNode(r);
            temp->next = newNode;
            temp = newNode;
            carry/=10;
        }
        return ans;
        
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = reverseList(l1);
        ListNode* L2 = reverseList(l2);
        ListNode* ans = addition(L1,L2);
        return reverseList(ans);
    }
};