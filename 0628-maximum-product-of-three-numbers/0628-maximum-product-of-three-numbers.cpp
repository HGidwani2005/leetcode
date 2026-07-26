class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        int res2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            res=nums[n-1]*nums[n-2]*nums[n-3];
            res2=nums[0] * nums[1] * nums[n-1];
        }
        return max(res,res2);
    }
};