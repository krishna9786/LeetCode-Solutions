class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int maxLength = 0;  // Maximum length of the alternating subarray
    int start = 1;     // Start index of the current potential subarray
    int previous = INT_MAX;  // Index of the previous element in the potential subarray

    // Check if the first element satisfies the conditions
    if (nums[0] <= threshold && nums[0] % 2 == 0)
        previous = 0;

    // Iterate through the elements of nums
    while (start < nums.size()) {
        // Check if the current element violates the conditions
        if (nums[start] > threshold || ((nums[start] % 2) == (nums[start - 1] % 2))) {
            // Calculate the length of the previous potential subarray
            int length = start - previous;
            // Update maxLength if the length is greater
            maxLength = max(maxLength, length);
            // Reset previous to mark the end of the current subarray
            previous = INT_MAX;
        }

        // Check if a new potential subarray can start
        if (previous == INT_MAX && nums[start] <= threshold && nums[start] % 2 == 0)
            previous = start;

        start++;  // Move to the next element
    }

    // Calculate the length of the last potential subarray
    int length = start - previous;
    // Update maxLength if the length is greater
    maxLength = max(maxLength, length);

    return maxLength;
}
};
