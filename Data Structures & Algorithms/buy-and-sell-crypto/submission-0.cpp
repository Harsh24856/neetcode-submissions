class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        stack<int> st;
        st.push(prices[0]);
        for(int i=1;i<n;i++){
            if(prices[i]<st.top()){
                st.push(prices[i]);
            }
            else{
                profit=max(profit,prices[i]-st.top());
            }
        }
        return profit;
        
    }
};
