class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int sum_ele=0;
        for(int i=0;i<n;i++){
            sum_ele+=nums[i];
        }
        int sum_dig=0;
        for(int i=0;i<n;i++){
            while(nums[i]>0){
                int digit=nums[i]%10;
                sum_dig+=digit;
                nums[i]=nums[i]/10;
            }
        
        }
        return sum_ele-sum_dig;
    }
};