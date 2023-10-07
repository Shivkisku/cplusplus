#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for(int i = m - 1, j = n - 1; j >= 0;) {
            nums1[i + j + 1] = (i < 0 || nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
        }
    }
};

int main() {
    Solution solution;

    // Test case
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3; // Number of elements in nums1
    int n = 3; // Number of elements in nums2

    solution.merge(nums1, m, nums2, n);

    std::cout << "Merged Array: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
