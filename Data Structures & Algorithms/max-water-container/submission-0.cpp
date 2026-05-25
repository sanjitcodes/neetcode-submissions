class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int start = 0;
        int end = n-1;

        while(start < end){
            int tmp = min(heights[start], heights[end])*(end - start);
            ans = max(ans, tmp);
            if(heights[start] <= heights[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};
