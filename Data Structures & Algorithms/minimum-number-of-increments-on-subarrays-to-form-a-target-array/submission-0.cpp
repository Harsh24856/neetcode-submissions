class Solution {
    int step=0;
    void ans(vector<int>& target,int& idx){
        if(idx==target.size())return;
        for(int i=idx;i<target.size();i++){
            if(target[i]>0){
                target[i]--;
            }
            else{break;}
        }
        while(idx<=target.size()-1 && target[idx]==0){
            idx++;
        }
        step++;
        ans(target,idx);
    }
public:
    int minNumberOperations(vector<int>& target) {
        int idx=0;
        ans(target,idx);
        return step;
        
    }
};