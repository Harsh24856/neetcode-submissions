class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int k=target-nums[i];
            if(mp.count(k) && mp[k]!=i){
                return {i,mp[k]};
            }
        }
        return{};
    }
};
