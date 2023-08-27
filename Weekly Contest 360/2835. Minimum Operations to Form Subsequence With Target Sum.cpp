/*
Author: darkflameace97

This code implements an algorithm to find the minimum number of operations needed to reduce the 
elements in the 'nums' vector such that their bitwise OR operation results in a value less than 
or equal to 'target'.

The approach involves counting the numbers with the same highest set bit position and 
iteratively adjusting the counts to achieve the desired result.

*/

class Solution {
public:
    int minOperations(std::vector<int>& nums, int target) {
        // Initialize an array to store counts of numbers with the same highest set bit position
        std::vector<int> c(31, 0);
        long long s = 0;
        int n = nums.size();

        // Calculate the sum of all numbers in the 'nums' vector
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            c[int(std::log2(x))]++;
            s += x;
        }

        // If the sum is less than 'target', return -1 as it's not possible to achieve the target value
        if (s < target) {
            return -1;
        }

        int i = 0, res = 0;

        // Traverse through each bit of 'target'
        while (i < 30) {
            // If the current bit is set (1)
            if ((1 << i) & target) {
                // Check if there's a number with the same bit position
                if (c[i] > 0) {
                    c[i]--;
                } 
                // If not, move to the next higher bit position
                else {
                    while (i < 30 && c[i] == 0) {
                        i++;
                        res++;
                    }
                    c[i]--;
                    continue;
                }
            }

            // Update the count of numbers in the next higher bit position
            c[i + 1] += c[i] / 2;
            i++;
        }
        
        return res; 
    }
};
