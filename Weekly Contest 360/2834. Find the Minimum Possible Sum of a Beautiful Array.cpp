/*
Author: darkflameace97

Explanation:
- Given the values 'n' and 'target', we want to find an array of 'n' distinct integers such that the sum of the array elements is minimized and no two elements sum up to 'target'.
- We start with 'curr' as 1 and keep adding elements to the set 's' while ensuring that the element 'target - curr' is not already present in the set.
- This approach guarantees that the sum of the array elements is minimized while satisfying the given condition.
- We keep track of the count 'cnt' of added elements and the cumulative sum 'sum' of the array elements.
- Once we have added 'n' distinct elements to the set, we return the 'sum' as the minimum possible sum.

Algorithm:
1. Initialize 'curr' as 1, 'cnt' as 0, 'sum' as 0, and an empty set 's'.
2. Run a loop while 'cnt' is less than 'n':
    a. Calculate the value 'num' as 'target - curr'.
    b. Check if 'num' is not present in the set 's':
        - If not present, insert 'curr' into the set, increment 'cnt', and add 'curr' to 'sum'.
    c. Increment 'curr'.
3. Return 'sum' as the minimum possible sum of the array.

*/

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int curr = 1;
        int cnt = 0;
        long long sum = 0;
        set<int> s;
        
        while (cnt < n) {
            int num = target - curr;
            if (s.find(num) == s.end()) {
                s.insert(curr);
                cnt++;
                sum += curr;
            }
            curr++;
        }
        return sum;
    }
};
