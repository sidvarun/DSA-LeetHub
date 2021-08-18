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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val > l2->val)
            return mergeTwoLists(l2, l1);
        ListNode* curr = l1;
        ListNode* curr1 = l1->next;
        ListNode* curr2 = l2;
        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                curr->next = curr2;
                curr2 = curr2->next;
            }
            else{
                curr->next = curr1;
                curr1 = curr1->next;
            }
            curr = curr->next;
        }
        if(curr1)
            curr->next = curr1;
        if(curr2)
            curr->next = curr2;
        return l1;
    }
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = NULL;
        if(n == 0)
            return head;
        if(n == 1)
            return lists[0];
        head = lists[0];
        for(int i = 1; i<n; i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};