// Leetcode Problem 242 : https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort both and compare
        // if s.length() = n and t.length() = m 
        // TC -> O(nlogn) + O(mlogm) // SC -> O(1)

        int n = s.length();
        int m = t.length();
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        // XOR all to get 0
        // Since each character should appear exactly twice
        // TC -> O(n) + O(m)
        // Will not work in cases of "a" and "abb"
        // Here the xor is still 0 but they are not anagrams
        
        // int xorr = 0;
        // for(int i=0; i<n; i++){
        //     xorr^=s[i];
        // }
        // for(int j=0; j<m; j++){
        //     xorr^=t[j];
        // }
        // return xorr==0;

        // Hashmap
        // TC -> O(n)+O(m)
        // SC -> O(n)

        if(n!=m) return false;
        // unordered_map<char,int>mp;
        // for(auto it : s) mp[it]++;
        // for(auto it : t){
        //     if(mp.find(it)==mp.end() || mp[it]==0) return false;
        //     else if(mp[it]>=1) mp[it]-=1;
        // }

        // for(auto it : mp){
        //     if(it.second>1) return false;
        // } return true;


        // Take an array of size 26 (max alphabets)
        // One string is strictly adder and the other is strictly reducer so for array element to remain 0, both have to contribute
        // And use it as hashmap for O(1) accesses
        // TC = O(n)+O(m)
        // SC = O(26) or O(1) constant space

        vector<int>v(26,0);
        for(int i =0; i<n; i++)
        {
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }

        for(int i=0; i<26; i++)
        {
            if(v[i]!=0) return false;
        }
        return true;
    }
};
