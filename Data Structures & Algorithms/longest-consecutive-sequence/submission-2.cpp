class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int x: nums){
            m.insert(x);
        }
        int ans = 0;
        for(int x: nums){
            if(m.find(x-1) == m.end()){
                int tmp = x;
                int count = 0;
                while(m.find(tmp) != m.end()){
                    ++count;
                    ++tmp;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
