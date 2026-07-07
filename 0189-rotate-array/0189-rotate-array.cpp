class Solution {
public:
    void reverseP(int i,int j,vector<int>&v){
        while(i<j){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;

        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverseP(0,n-k-1,nums);
        reverseP(n-k,n-1,nums);
        reverseP(0,n-1,nums);
        
    }
   
};