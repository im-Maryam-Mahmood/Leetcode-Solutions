class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> merged(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            merged[k++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++];
        }
        while (i <= mid) merged[k++] = nums[i++];
        while (j <= right) merged[k++] = nums[j++];
        for (int p = 0; p < merged.size(); p++) nums[left + p] = merged[p];
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;

    }
};