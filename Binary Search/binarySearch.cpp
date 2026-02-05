// Leetcode 704: Binary Search : https://leetcode.com/problems/binary-search/

class Solution {
public:

    // Iterative Binary search for Sorted Sequences
    // Time Complexity : O(logN)
    // Space Complexity : O(1)  

    // Recursive Binary Search for Sorted Sequences
    // Time Complexity : O(logN)
    // Space Complexity : O(logN)

    void recursiveBinarySearch(int left, int right, vector<int>&nums, int &target, int &ans){
        if(left>right) return;

        int mid = left + (right-left)/2;

        if(nums[mid]==target) {
            ans = mid; 
            return;
        }

        else if(nums[mid]>target){
            recursiveBinarySearch(left,mid-1,nums,target,ans);
        }
        
        else {
            recursiveBinarySearch(mid+1,right,nums,target,ans);
        }
    }


    int search(vector<int>& nums, int target) {

        int ans = -1;
        int n = nums.size();
        recursiveBinarySearch(0,n-1,nums,target,ans);

        // int left = 0;
        // int right = n-1;

        // while(left<=right){

        //     int mid = left+ (right-left)/2;

        //     if(nums[mid]==target){
        //         ans = mid;
        //         break;
        //     }

        //     else if(nums[mid]>target){
        //         right = mid-1;
        //     } 

        //     else left = mid+1;

        // }

        return ans;

    }
};
