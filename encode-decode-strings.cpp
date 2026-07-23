class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (const auto &str: strs) {
            result += to_string(str.length()) + " " + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result {};
        size_t i = 0; 
        while (i < s.length()) {
            size_t start_pos = i;
            while (isdigit(s[i])) {
                ++i;
            }
            int str_length = stoi(s.substr(start_pos, i - start_pos));
            result.push_back(s.substr(i + 1, str_length));
            i += str_length + 1;
        }
        return result;
    }
};
