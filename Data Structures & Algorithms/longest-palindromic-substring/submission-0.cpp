class Solution {
public:
    string longestPalindrome(string s) {
        int l=0,r=0,best=0,n=s.size();
        if(n <= 1) return s;
        string ans=s.substr(0, 1);
        best = 1;
        for(int i=0;i<n;i++){
            
            l=i; r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--; r++;
            }
            if(best < r - l - 1){
                best = r - l - 1;
                ans = s.substr(l + 1, best);
            }
            l=i; r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--; r++;
            }
            if(best < r - l - 1){
                best = r - l - 1;
                ans = s.substr(l + 1, best);
            }
        }
        return ans;
    }
};