class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return {};

        sort(nums.begin(), nums.end());

        if(nums[0] + nums[1] + nums[2] > 0 ||
           nums[n-1] + nums[n-2] + nums[n-3] < 0) {
            return {};
        }

        vector<vector<int>> sum;

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int a = nums[i];

            int l = i + 1;
            int r = n - 1;

            while(l < r) {

                int currentSum = a + nums[l] + nums[r];

                if(currentSum == 0) {

                    sum.push_back({a, nums[l], nums[r]});

                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l-1])
                        l++;

                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }

                else if(currentSum > 0) {
                    r--;
                }

                else {
                    l++;
                }
            }
        }

        return sum;
    }
};