// Leetcode 217 -> https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // O(N^2) loop -> TLE 
        // unordered set maintain -> O(N) Time + O(N) Space
        // sort nums[i] == nums[i+1] -> Time O(NlogN) + O(N)
        // unordered set size compared at end -> roughly O(N) time + O(N) space
        
        int n = nums.size();

        // for(int i = 0; i<n; i++)
        // {
        //     for(int j = i+1; j<n; j++)
        //     {
        //         if(nums[i]==nums[j]) return true;
        //     }
        // }
        // return false;

        // unordered_set<int>numbers;
        // for(int i=0; i<n; i++){
        //     if(numbers.find(nums[i])==numbers.end()){
        //         numbers.insert(nums[i]);
        //     } else return true;
        // }
        // return false;

        // sort(nums.begin(),nums.end());
        // for(int i=0; i<n-1; i++){
        //     if(nums[i]==nums[i+1])
        //     return true;
        // } return false;
        
        // unordered_set<int>numbers;
        // for(auto i : nums) numbers.insert(i);
        // return numbers.size()!=nums.size();

    }
};
