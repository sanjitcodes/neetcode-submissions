class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for(char &c: s){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                st += tolower(c);
            }
        }
        string t = st;
        reverse(t.begin(), t.end());
        return (st == t);
    }
};
