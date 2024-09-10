// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description
// 2807 - Insert Greatest Common Divisors in Linked List

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *back = head, *front = head, *aux;
        if(head->next!=nullptr)
            front = head->next;
        else return head;

        while(1){
            aux = new ListNode;
            aux->val = gcd(back->val,front->val);
            back->next = aux;
            aux->next = front;
            if(front->next==nullptr)
                break;
            back = front;
            front = front->next;
        }

        return head;
    }
};
