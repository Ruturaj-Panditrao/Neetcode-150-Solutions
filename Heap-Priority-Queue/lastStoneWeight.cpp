// Leetcode 1046: Last Stone Weight : https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Time Complexity : O(nlogn)
        // N elements, each pushed by log n 
        // And while loop, each pop requires log n,
        // And push requires logn and max n collisions

        // Space Complexity : O(n) 

        priority_queue<int>pq;

        for(auto it : stones) pq.push(it);
        int ans = 0;
        while(!pq.empty()){
            if(pq.size()==1){
                ans = pq.top();
                pq.pop();
                break;
            } 

            int ftop = pq.top();
            pq.pop();
            int stop = pq.top();
            pq.pop();

            if(ftop!=stop){
                pq.push(ftop-stop);
            }
        }

        return ans;
    }
};
