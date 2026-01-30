// Leetcode  136 -> https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Strict constraints already given in problem
        // O(N) time and O(1) space solution
        int ans = 0;
        for(int i=0; i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};
