class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> wordsMap;
        for (const auto& str: strs) {
            array<int, 26>wordMap {};
            for (const auto& ch: str) {
                wordMap[ch - 'a']++;
            }
            wordsMap[wordMap].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& pair: wordsMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};
