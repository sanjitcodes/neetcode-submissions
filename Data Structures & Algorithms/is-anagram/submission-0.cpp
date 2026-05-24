class Solution {
public:
    bool isAnagram(string s, string t) {
        string s1 = s, s2 = t;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return (s1 == s2);
    }
};
