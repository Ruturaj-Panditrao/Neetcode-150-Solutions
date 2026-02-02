// Leetcode 125: https://leetcode.com/problems/valid-palindrome/
// TC -> O(N) and SC -> O(1)

class Solution {
public:

    bool isAlphanumeric(char ch)
    {
        return 
        (ch >='a' && ch<='z') || (ch >='A' && ch<='Z') || (ch>='0' && ch<='9');
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        char lchar = 'a';
        char rchar = 'z';

        while(left<right){
            if(isAlphanumeric(s[left]))
            {
                lchar = tolower(s[left]);
            } else {
                left++;
                continue;
            }

            if(isAlphanumeric(s[right]))
            {
                rchar = tolower(s[right]);
            } else {
                right--;
                continue;
            }

            if(lchar==rchar){
                left++;
                right--;
            } else return false;
        }
        return true;
    }
};
