// 191. Number of 1 Bits : https://leetcode.com/problems/number-of-1-bits/description/

// Time Complexity : O((number of bits)*(set bit count))
// Space Complexity : O(set bits)
class Solution {
public:
    int hammingWeight(int n) {
        if(n<=1) return n;
        long long int nearest2Factor = 1;
        while(nearest2Factor<n){
            nearest2Factor*=2;
        }
        if(nearest2Factor>n) nearest2Factor/=2;
        if(nearest2Factor*2==n) return 1;
        else return 1 + hammingWeight(n-nearest2Factor);
    }
};

// Time Complexity : O(Number of bits) 
// We process each bit at a time
// Space Complexity : O(1)
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;

        while(n!=0){
            if(n%2==1) ans++;
            n>>=1;
        }

        return ans;
    }
};

// Time Complexity : O(set number of bits)
// Space Complexity : O(1)
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;

        while(n!=0){
            n&=(n-1);
            ans++;
        }

        return ans;
    }
};
