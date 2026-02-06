// Leetcode 206 : https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode* reverseList(ListNode* head) {
        // Brute force approach will be:
        // Store all the node data in an array  
        // Overwrite existing list with reversed data if allowed 
        // Or create a new list with the reversed order
        // Time Complexity : O(N)
        // Space Complexity : O(N)

        vector<int>nodes;

        ListNode* start = head;

        while(start!=NULL){
            nodes.push_back(start->val);
            start = start->next;
        }

        start = head;

        for(int i=0; i<nodes.size(); i++){
            start->val = nodes[nodes.size()-i-1];
            start = start->next;
        }

        return head;

        // For just 2 nodes
        // 1, 2
        // head -> 1 address
        // 1 -> 2 address

        // head -> (1->next) -> head->next

        // For just 3 nodes
        // 1,2,3
        // head -> 1 address, 1-> 2 address, 2 -> 3 address
        // travel to the end and swap one pair each time
        // But this seems like Bubble Sort and will require O(N^2) time

        // 2 pointer approach?
        // Yes, it is optimal and will require O(N) time but just O(1) space
        // But how do I do right--?
        // I can avoid right-- by setting left as mid-1 and right as mid+1
        // But then how do I do left--?
        
        // Using 2 pointers
        // Time Complexity : O(N)
        // Space Complexity : O(1)
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* nextnode = curr->next;
            curr->next = prev;
            nextnode->next = curr;
            curr = nextnode;
            prev = curr;
        }

        return prev;
    }
};
