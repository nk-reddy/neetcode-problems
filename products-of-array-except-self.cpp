// Naive Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) {
                    continue;
                }
                result[i] *= nums[j];
            }
        }
        return result;
    }
};

// Solution Two
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        for (int i = 0; i < nums.size(); i++) {
            totalProduct *= nums[i];
        }
        vector<int> result(nums.size(), totalProduct);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                result[i] = 1;
                for (int j = 0; j < nums.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    result[i] *= nums[j];
                }
                continue;
            }
            result[i] /= nums[i];
        }
        return result;
    }
};

// Better Divisior Implementation
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0;
        int product_nonzero = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zero_count++;
                continue;
            }
            product_nonzero *= nums[i];
        }

        if (zero_count > 1) {
            return vector<int>(nums.size(), 0);
        }

        vector<int>result(nums.size());
        if (zero_count == 1) {
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    result[i] = product_nonzero;
                    continue;
                }
                result[i] = 0;
            }
            return result;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            result[i] = product_nonzero / nums[i];
        }
        return result;
    }
};

// left / right products solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>rightProd(nums.size(), 1);
        vector<int>leftProd(nums.size(), 1);
        vector<int>result(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                leftProd[i] = nums[i - 1] * leftProd[i - 1];
            }
            if (i != nums.size() - 1) {
                rightProd[i] *= nums[i + 1];
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i != nums.size() - 1) {
                rightProd[i] *= rightProd[i + 1];
            }
            result[i] = leftProd[i] * rightProd[i];
        }
        return result;
    }
};

// O(N) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>rightProd(nums.size(), 1);
        vector<int>result(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            result[i] = nums[i - 1] * result[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            right *= nums[i + 1];
            result[i] *= right;
        }
        return result;
    }
};


