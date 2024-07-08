// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description
// 1823 - Find the Winner of the Circular Game

class Solution {
public:
    struct Node {
        int val;
        Node* next;
    };

    typedef Node node;

    int findTheWinner(int n, int k) {
        node* head = new node;
        node* aux=head;
        head->val=1;
        for(int i=2; i<=n; ++i){
            aux->next = new node;
            aux=aux->next;
            aux->val=i;
        }
        aux->next=head;
        int count=0;
        while(head->next != head){
            for(int i = 1; i<k; ++i){
                aux=aux->next;
                head = head->next;
            }
            head = aux->next = head->next;
        }
        return head->val;
    }
};
