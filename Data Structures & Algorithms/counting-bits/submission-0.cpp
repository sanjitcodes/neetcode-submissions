class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++){
            int tmp = i;
            int cnt = 0;
            while(tmp){
                tmp = tmp & (tmp-1);
                ++cnt;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
