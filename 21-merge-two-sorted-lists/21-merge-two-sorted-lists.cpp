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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        //In- place
        //decide starting node: whiever is lesser
        ListNode* curr = new ListNode(0, NULL);
        
        if(list1->val <= list2->val){
            curr = list1;
            list1 = list1->next;
        }
        else{
            curr = list2;
            list2 = list2->next;
        }
        ListNode* head = curr;  //to return head
        
        //start merging (merge sort)
        while(list1 && list2){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            }
            else{
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        if(list1)
            curr->next = list1;
        else
            curr->next = list2;
        
        return head;
    }
};