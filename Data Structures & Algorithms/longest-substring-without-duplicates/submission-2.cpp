class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,best=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(r<n){
            while(mp[s[r]]>=1){
                mp[s[l]]--;
                l++;
            }
            best=max(best,r-l+1);
            mp[s[r]]++;
            r++;
        }
        return best;
    }
};