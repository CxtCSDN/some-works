#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>

using namespace std;

class Solution {
public:
    //寻找消失的数字
    int missingNumber(vector<int>& nums) {
        int a = 0;
        for (auto& i : nums) {
            a ^= i;
        }
        for (int i = 0; i <= nums.size(); i++) {
            a ^= i;
        }
        return a;
    }
    //移除数组中的某一元素
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                fast++;
                slow++;
            }
            else {
                fast++;
            }
        }
        return slow;
    }
    //合并两个有序数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = nums1.size() - 1;
        int end1 = m - 1, end2 = n - 1;
        while (end1 >= 0 && end2 >= 0) {
            if (nums1[end1] > nums2[end2]) {
                nums1[end] = nums1[end1];
                end1--;
                end--;
            }
            else {
                nums1[end] = nums2[end2];
                end--;
                end2--;
            }
        }
        while (end2 >= 0) {
            nums1[end] = nums2[end2];
            end--;
            end2--;
        }
    }
    //右旋数组
    void m_reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        m_reverse(nums, 0, nums.size() - 1);
        m_reverse(nums, 0, k - 1);
        m_reverse(nums, k, nums.size() - 1);
    }
};