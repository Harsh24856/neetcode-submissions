class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        vector<int> ans(n);
        queue<int> enter, exit;
        int prev = 1;
        int t = 0;
        int i = 0;
        while (i < n || !enter.empty() || !exit.empty()) {
            while (i < n && arrival[i] <= t) {
                if (state[i] == 1) exit.push(i);
                else enter.push(i);
                i++;
            }
            if (enter.empty() && exit.empty()) {
                t = arrival[i];
                prev = 1;
                continue;
            }
            if (prev == 1) {
                if (!exit.empty()) {
                    ans[exit.front()] = t;
                    exit.pop();
                    prev = 1;
                } else {
                    ans[enter.front()] = t;
                    enter.pop();
                    prev = 0;
                }
            } else {
                if (!enter.empty()) {
                    ans[enter.front()] = t;
                    enter.pop();
                    prev = 0;
                } else {
                    ans[exit.front()] = t;
                    exit.pop();
                    prev = 1;
                }
            }
            t++;
        }
        return ans;
    }
};