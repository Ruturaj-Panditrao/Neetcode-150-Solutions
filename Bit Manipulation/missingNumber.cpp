// Leetcode 268 : Missing Number : https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR approach 
        // Sum of n natural numbers approach
        // Time Complexity : O(n)
        // Space Complexity : O(1)
        
        int n = nums.size();
        // int xor_val = 0;
        // for(int i=0; i<=n; i++){
        //     xor_val^=i;
        //     if(i<n){
        //         xor_val^=nums[i];
        //     }
        // } 

        // return xor_val;

        int sum_natural = n*(n+1);
        sum_natural/=2;

        int cur_sum = 0;
        for(auto it : nums) cur_sum+=it;

        return sum_natural-cur_sum;
    }
};
