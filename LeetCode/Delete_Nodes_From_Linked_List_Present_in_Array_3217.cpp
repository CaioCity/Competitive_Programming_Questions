// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// 3217 - Delete Nodes From Linked List Present in Array

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> S (nums.begin(),nums.end());
        ListNode *back = head, *front;
        
        while(back!=nullptr && back->next!=nullptr){
            front = back->next;
            if(S.find(front->val)!=S.end()){
                while(front!=nullptr && S.find(front->val)!=S.end())
                    front = front->next;
                back->next = front;
            }
            back = back->next;
        }

        if(S.find(head->val)!=S.end())
            head = head->next;

        return head;
    }
};
