class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
            m[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            if(s.find(target-nums[i]) != s.end() && i!=m[target-nums[i]]){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};
