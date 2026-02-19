// 338. Counting Bits : https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
// Time Complexity : O(nlogn)
// Space Complexity : O(n)
    int countSetBits(int n){
        int setbits = 0;
        while(n!=0){
            n&=n-1;
            setbits++;
        }
        return setbits;
    }

    vector<int> countBits(int n) {
        vector<int>ans;

        for(int i=0; i<=n; i++){
            ans.push_back(countSetBits(i));
        }

        return ans;
    }
};

class Solution {
public:

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    // It is the same recurrence I naturally derived in the hammingWeight problem
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        int pow = 1;

        for(int i=1; i<=n; i++){
            if(i==pow*2) pow*=2;
            dp[i] = 1 + dp[i-pow];
        }

        return dp;
    }
};
