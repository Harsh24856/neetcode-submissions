class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>>available;
        for(int i=0;i<n;i++)available.push(i);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> busy;
        sort(meetings.begin(),meetings.end());
        vector<int> count(n,0);
        for(auto it:meetings){
            long long start=it[0];
            long long end=it[1];
            long long duration=end-start;
           while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
             if (!available.empty()) {
                int room = available.top();
                available.pop();
                count[room]++;
                busy.push({end, room});
            }
            else {
                auto [freeTime, room] = busy.top();
                busy.pop();
                count[room]++;
                busy.push({freeTime + duration, room});
            }

        }
        return max_element(count.begin(), count.end()) - count.begin();
    }
};