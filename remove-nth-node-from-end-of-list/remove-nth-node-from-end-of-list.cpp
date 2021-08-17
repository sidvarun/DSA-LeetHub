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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        if(head == NULL)
            return head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        int k = count - n - 1;
        ListNode* curr1 = head;
        if(k == -1){
            head = head->next;
            return head;
        }
        while(k-- && curr1){
            curr1 = curr1->next;
        }
        if(curr1->next)
            curr1->next = curr1->next->next;
        else
            curr1->next = NULL;
        return head;
    }
};