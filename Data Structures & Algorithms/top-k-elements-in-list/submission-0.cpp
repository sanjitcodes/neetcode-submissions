class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for(auto x: nums){
            f[x]++;
        }
        priority_queue<pair<int, int> > pq;
        for(auto [a, b]: f){
            pq.push({b, a});
        }
        vector<int> ans;
        while(k--){
            auto [b, a] = pq.top();
            pq.pop();
            ans.push_back(a);
        }
        return ans;
    }
};
