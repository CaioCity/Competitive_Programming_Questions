// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description
// 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* node, int* returnSize) {
    int index=1, min=INT32_MAX, first, last, n=0;
    int val_last;
    *returnSize = 2;
    int* ans=(int*)malloc(2*sizeof(int));
    ans[0]=ans[1]=-1;
    
    if(node->next==NULL || node->next->next==NULL)
        return ans;

    val_last = node->val;
    node = node->next;

    while(node->next!=NULL){
        if( (node->val< val_last && node->val < node->next->val) || 
            (node->val > val_last && node->val > node->next->val) ){
                if(n==0)
                    first=index;
                else
                    min= (min > (index-last))? (index-last) : min;
                ++n;
                last=index;
            }
        val_last=node->val;
        ++index;
        node=node->next;
    }

    if(n<2)
        return ans;
        
    ans[0]=min, ans[1]=last-first;
    return ans;
}
