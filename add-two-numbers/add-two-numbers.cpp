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
        int carry = 0;
        // ListNode* curr1 = l1;
        // ListNode* curr2 = l2;
        ListNode* head = new ListNode((l1->val + l2->val)%10);
        ListNode* curr = head;
        carry = (l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2){
            int sum = 0;
            sum = (l1->val + l2->val + carry);
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while(l1){
            int sum = 0;
            sum = (l1->val + carry);
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2){
            int sum = 0;
            sum = (l2->val + carry);
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            curr = curr->next;
        }
        while(carry){
            curr->next = new ListNode(carry%10);
            carry = carry/10;
            curr = curr->next;
        }
        return head;
    }
};