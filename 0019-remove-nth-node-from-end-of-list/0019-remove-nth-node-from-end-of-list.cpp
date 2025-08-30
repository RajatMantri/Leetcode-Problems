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
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*fast=head,*slow=head;
        int k=n;
        while(k--){
            fast=fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};