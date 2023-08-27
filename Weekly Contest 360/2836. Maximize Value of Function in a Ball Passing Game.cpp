/*
Author: darkflameace97

Explanation:
- For each player 'x', we want to maximize the function f(x), which is the sum of x and the ids of players who receive the ball during k passes.
- We precompute parent-child relationships and path sums using dynamic programming for efficient calculation of f(x).
- We iterate through each player and compute the parent-child relationships and path sums for k passes.
- Then, for each possible starting player 'x', we calculate f(x) by traversing the path and summing up the values.
- The maximum f(x) value across all starting players is the result we seek.
*/

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        vector<vector<int>> child(n, vector<int>(35));
        vector<vector<long long>> sum(n, vector<long long>(35));

        // Initialize child and sum vectors for the initial pass
        for (int i = 0; i < n; i++) {
            child[i][0] = receiver[i];
            sum[i][0] = i + receiver[i];
        }

        // Precompute child relationships and sum values for subsequent passes
        for (int j = 1; j <= 34; j++) {
            for (int i = 0; i < n; i++) {
                child[i][j] = child[child[i][j - 1]][j - 1];
                sum[i][j] = sum[i][j - 1] + sum[child[i][j - 1]][j - 1] - child[i][j - 1];
            }
        }

        long long maxi = 0;
        for (int i = 0; i < n; i++) {
            int cur = i, len = 0;
            long long tmp = 0;

            // Calculate f(x) value for each starting player
            for (int j = 0; j <= 34; j++) {
                if ((k & (1LL << j))) {
                    tmp += sum[cur][j];
                    if (len)
                        tmp -= cur;
                    else
                        len = 1;
                    cur = child[cur][j];
                }
            }

            // Update maximum f(x) value
            maxi = max(maxi, tmp);
        }
        return maxi;
    }
};
