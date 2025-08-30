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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode*o=head,*e=head->next;
        ListNode*p=head->next;

        while(e!=NULL){
            o->next=e->next;
            if(o->next){
                o=o->next;
                e->next=o->next;
                e=e->next;
            }
            else{
                break;
            }
        }

        o->next=p;

        return head;
    }
};