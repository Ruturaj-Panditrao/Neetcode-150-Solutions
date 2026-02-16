// Leetcode 70: Climbing Stairs : https://leetcode.com/problems/climbing-stairs/description/

class Solution {
// Time Complexity : O(n)
// Space Complexity : O(1)
public:
    int climbStairs(int n) {
        int f = 0;
        int s = 1;
        for(int i=0; i<n; i++){
            int newNum = f+s;
            f = s;
            s = newNum;
        }
        return s;
        
    }
};

class Solution {
// Time Complexity : O(n)
// Space Complexity : O(n) dp + O(n) stack space
public:
    int findWays(int n, vector<int>&dp){
        if(dp[n]!=-1) return dp[n];
        
        dp[n] = findWays(n-1,dp) + findWays(n-2,dp);
        return dp[n];
    }

    int climbStairs(int n) {

        vector<int>dp(n+1,-1);
        for(int i=0; i<=n; i++){
            if(i<=3) dp[i] = i;
            else break;
        }
        return findWays(n,dp);
       
    }
};

class Solution {
// Time Complexity : O(2^N)
// Space Complexity : O(N)
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n<=3) return n;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};
