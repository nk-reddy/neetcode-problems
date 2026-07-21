class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { return false; }
        map<char, int> str1;
        map<char, int> str2;
        for (int i = 0; i < s.length(); i++) {
            if (t.find(s[i]) == string::npos) {
                return false;
            }
            str1[s[i]]++;
            str2[t[i]]++;
        }
        return str1 == str2;
    }
};
