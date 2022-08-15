#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        if (nums.size() % 2 != 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int first = 0, second = 1;
        while (second < nums.size()) {
            if (nums[first] == nums[second]) {
                first += 2;
                second += 2;
            }
            else {
                ans.push_back(nums[first]);
                if (second + 1 == nums.size()) {
                    ans.push_back(nums[second]);
                    break;
                }
                second += 1;
                first += 1;
            }
        }
        if (first == nums.size() - 1) {
            ans.push_back(nums[first]);
        }
        return ans;
    }
};