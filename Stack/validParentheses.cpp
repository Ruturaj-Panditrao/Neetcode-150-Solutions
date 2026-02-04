// Leetcode 20. Valid Parentheses: https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        // Use a stack to keep track 
        // Time Complexity -> O(N)
        // Space Complexity - > O(N)
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                char curTop = st.top();

                if (
                    (curTop == '(' && s[i] == ')') ||
                    (curTop == '{' && s[i] == '}') ||
                    (curTop == '[' && s[i] == ']')
                ) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        return st.empty() == true;
    }
};
