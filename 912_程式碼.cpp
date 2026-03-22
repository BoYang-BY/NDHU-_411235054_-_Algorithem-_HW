class Solution {
public:
    void quick(vector<int>& nums, int a, int b) {
        if (a >= b) return;

        int i = a;
        int j = b;
        int pivot = nums[(a+b)/2];

        while (i <= j) {
            while (nums[i] < pivot) i++;
            while (nums[j] > pivot) j--;

            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }

        quick(nums,a,j);
        quick(nums,i,b);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick(nums,0,nums.size()-1);
        return nums;
    }
};