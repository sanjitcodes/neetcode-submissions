class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int x: nums){
            sum += x;
        }
        int n = nums.size();
        int exp_sum = (n+1)*(n);
        exp_sum /= 2;
        return (exp_sum - sum);
    }
};
