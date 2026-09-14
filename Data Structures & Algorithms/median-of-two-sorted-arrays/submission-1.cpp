class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        bool odd=((m+n)&1)?false:true;
        double ans=0;
        for(int k=0;k<=((m+n)/2);k++){
            if(j==m || (i<n && nums1[i]<=nums2[j])){
                if(odd && k==((m+n)/2)-1){
                    ans+=nums1[i];
                    }
                if(k==((m+n)/2)){ 
                    ans+=nums1[i];
                    }
                
                i++;}
            else if(i==n || (j<m && nums1[i]>nums2[j])){
                if(odd && k==((m+n)/2)-1){
                    ans+=nums2[j];
                    }
                if(k==((m+n)/2)){
                    ans+=nums2[j];
                    }
                j++;}

        }
        return (odd)?ans/2:ans;
        
    }
};