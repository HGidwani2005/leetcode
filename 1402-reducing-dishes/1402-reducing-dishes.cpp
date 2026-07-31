class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int suf[n];
        suf[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+satisfaction[i];
            
        }
        //find the pivot/max idx
        int idx=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        //calculate the max sum of ltc
        int x=1;
        int max_sum=0;
        for(int i=idx;i<n;i++){
            max_sum+=(satisfaction[i]*x);
            x++;
        }
        return max_sum;
    }
};