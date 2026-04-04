class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans(n,-1);

        int WindowSize = 2*k+1;
        if(WindowSize > n) return ans;

        long long sum = 0;

        for(int i=0 ; i<WindowSize; i++){
            sum = sum + nums[i]; 
        }

        ans[k] = sum/WindowSize;

        for(int i=WindowSize ; i<n ; i++){
            sum = sum + nums[i];
            sum = sum - nums[i-WindowSize];

            int center = i-k;
            ans[center] = sum/WindowSize;
        }
        return ans;
    }
};