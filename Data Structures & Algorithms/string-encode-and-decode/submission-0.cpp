class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s: strs){
            encoded += to_string(s.size()) + '#' + s; 
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while(i < s.size()){
            int j = i;
            string l = "";
            while(s[j] != '#'){
                l += s[j++];
            }
            int len = stoi(l);
            string d = s.substr(j+1, len);
            decoded.push_back(d);
            i = j+1+len;
        }
        return decoded;

    }
};
