// Leetcode 121 : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        // Brute force approach, check every combination
        // Time Complexity -> O(N^2)
        // Space Complexity -> O(1)

        // Skip the last element because it will never be sold
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(prices[j]<prices[i]) continue;
        //         else ans = max(ans,prices[j]-prices[i]);
        //     }
        // }

        // return ans;

        // Use Prefix and Suffix Array
        // Keep a track of min from left 
        // Keep a track of max from right
        // At that particular index
        // Time Complexity -> O(3N)
        // Space Complexiy -> O(2N) 

        // int lmin = prices[0];
        // int rmax = prices[n-1];

        // vector<int>lv(n,0);
        // for(int i=0; i<n; i++){
        //     lmin = min(prices[i],lmin);
        //     lv[i] = lmin;
        // }

        // vector<int>rv(n,0);
        // for(int i=n-1; i>=0; i--){
        //     rmax = max(prices[i],rmax);
        //     rv[i] = rmax;
        // }

        // for(int i=0; i<n; i++){
        //     ans = max(ans,rv[i]-lv[i]);
        // }

        // return ans;

        // We can achieve the same with 2 Pointers,
        // Keep a pointer to store minimum so far
        // And max profit is the max of existing profit (0)
        // And the profit gained by selling today if it was bought for minSoFar
        // Time Complexity -> O(N)
        // Space Complexity -> O(1)

        int minSoFar = prices[0];

        for(int i=0; i<n; i++){
            ans =  max(ans,prices[i]-minSoFar);
            minSoFar = min(minSoFar,prices[i]);
        }

        return ans;

    }
};
