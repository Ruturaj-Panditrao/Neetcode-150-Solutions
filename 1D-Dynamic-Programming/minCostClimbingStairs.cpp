// 746. Min Cost Climbing Stairs : https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Time Complexity : O(2^N)
// Space Complexity : O(N) 

class Solution {
public:

    void recurse(int i, int n, vector<int>&cost, int currentCost, int &ans){
        if(i==n){
            ans = min(ans,currentCost);
            return;
        }
        if(i>n) return;

        int totalCost = 0;
        if(i==-1) totalCost = currentCost;
        else totalCost = currentCost + cost[i];
        recurse(i+1,n,cost,totalCost,ans);
        recurse(i+2,n,cost,totalCost,ans);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int i = -1;
        int ans = INT_MAX;
        int n = cost.size();
        int currentCost = 0;
        recurse(i,n,cost,currentCost,ans);
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N) stack + O(N) dp 

class Solution {
public:

    int recurse(int i, vector<int>&cost, int n, vector<int>&dp){

        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];
        
        int stepOneCost = cost[i]+recurse(i+1,cost,n,dp);
        int stepTwoCost = cost[i]+recurse(i+2,cost,n,dp);

        dp[i] = min(stepOneCost,stepTwoCost);
        return min(stepOneCost,stepTwoCost);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int currentCost = 0;

        int startFromZero = recurse(0,cost,n,dp);
        int startFromOne = recurse(1,cost,n,dp);
        
        return min(startFromZero, startFromOne);
    }
};


// Time Complexity : O(N)
// Space Complexity : O(N) stack + O(N) dp 
class Solution {
public:

    int recurse(int i, vector<int>&cost, int n, vector<int>&dp){

        if(i>=n){
            return 0;
        }

        if(i!=-1 && dp[i]!=-1) return dp[i];

        int stepOneCost = recurse(i+1,cost,n,dp);
        int stepTwoCost = recurse(i+2,cost,n,dp);

        if(i!=-1){
            stepOneCost+=cost[i];
            stepTwoCost+=cost[i];
            dp[i] = min(stepOneCost,stepTwoCost);
        }
        

        return min(stepOneCost,stepTwoCost);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int currentCost = 0;

        return recurse(-1,cost,n,dp);
    }
};
