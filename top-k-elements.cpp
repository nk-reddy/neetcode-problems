// Naive Solution 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count {};
        for (const auto& num: nums) {
            count[num]++;
        }

        vector<int> keys;
        for (const auto& entry: count) {
            keys.push_back(entry.first);
        }

        sort(keys.begin(), keys.end(), 
        [&count](int a, int b) {
            return count[a] > count[b];
        });

        return vector<int>(keys.begin(), keys.begin() + k);
    }
};

// Bucket Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count {};
        for (const auto& num: nums) {
            count[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& pair: count) {
            buckets[pair.second].push_back(pair.first);
        }

        int cached = 0;
        vector<int> result {};
        for (int i = nums.size(); i > 0; --i) {
            for (const auto& val: buckets[i]) {
                if (cached < k) {
                    result.push_back(val);
                    cached++;
                }
                if (cached == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
