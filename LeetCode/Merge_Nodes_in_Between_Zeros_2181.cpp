// https://leetcode.com/problems/merge-nodes-in-between-zeros/description
// 2181 - Merge Nodes in Between Zeros

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head, *count = head;
        int sum;
        while(p->next!=NULL){
            p=p->next;
            sum=0;
            while(p->val!=0){
                sum+=(p->val);
                p=p->next;
            }
            count->val = sum;
            if(p->next!=NULL)
                count=count->next;
            else
                count->next=NULL;
        }

        return head;
    }
};
