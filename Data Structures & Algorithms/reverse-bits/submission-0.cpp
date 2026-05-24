class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        string s = "";
        for(int i=0; i<32; i++){
            if(1<<i & n){
                s.push_back('1');
            }
            else{
                s.push_back('0');
            }
        }
        for(int i=31; i>=0; i--)
            ans += (s[i] == '1') ? (1 << (31-i)) : 0;
        return ans;
    }
};
