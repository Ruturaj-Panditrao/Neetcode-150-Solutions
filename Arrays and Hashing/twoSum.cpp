// Leetcode 1 -> https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;

        // Brute force TC -> O(N^2)
        // Little optimization can be since it is guaranteed that only 1 solution exists
        // We can break/return as soon as we find a pair
        
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return ans;


        // Use an unordered_map
        // Put first element into the map with index
        // For subsequent elements, check if target-nums[i] is present in the map
        // TC -> O(N)
        // SC -> O(N)

        // unordered_map<int,int>mp;
        // size of nums will atleast be 2 always, as given
        // mp[nums[0]]=0; or mp.insert({nums[0],0});
        // for(int i=1; i<n; i++){
        //     auto it = mp.find(target-nums[i]);
        //     if(it!=mp.end()){
        //         int index = it->second;
        //         ans.push_back(i);
        //         ans.push_back(index);
        //         break;
        //     } else mp[nums[i]]=i;
        // }
        // return ans;

        // Sort the array 
        // Similar to above do binary search for each element similar to checking in hashmap
        // TC -> O(NlogN) sorting + O(N)*O(logN) binary search for each element is logN
        // SC -> O(1)
        // But sorting an array for binary search is not worth it

        // Sort the array
        // Use 2 pointer approach to find the answer
        // TC -> O(NlogN) sorting + O(N) 2 pointer traversal
        // SC -> O(N)

        // sort(nums.begin(),nums.end()); -> makes me lose indices! problem asks indices
        // Instead I should also store the original indices
        // Okay solution but hashmap one is more convinient
        
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());

        int left = 0;
        int right = n-1;

        while(left<right){
            int cursum = v[left].first+v[right].first;
            if(cursum==target){
                ans.push_back(v[left].second);
                ans.push_back(v[right].second);
                break;
            } else if (cursum>target) right--;
            else left++;
        } 

        return ans;
    }
};
