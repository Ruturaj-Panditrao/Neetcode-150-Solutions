// 190. Reverse Bits : https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
// Time Complexity : O(1)
// Space Complexity : O(1)
    int reverseBits(int n) {
        int res = 0;
        int pos = 0;
        while(n!=0){
            int lastBit = n&1;
            n>>=1;
            lastBit<<=(31-pos);
            res|=lastBit;
            pos+=1;
        }
        return res;
    }
};
