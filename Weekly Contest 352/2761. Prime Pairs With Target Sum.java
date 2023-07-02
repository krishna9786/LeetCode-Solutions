import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        // First calculate the prime numbers
        boolean[] prime = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            prime[i] = true;
        }

        for (int i = 2; i <= n; i++) {
            if (!prime[i]) {
                continue;
            }
            for (int j = 2 * i; j <= n; j += i) {
                prime[j] = false;
            }
        }

        // Iterate and find the pairs whose sum is equal to n
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 2; 2 * i <= n; i++) {
            if (prime[i] && prime[n - i]) {
                List<Integer> pair = new ArrayList<>();
                pair.add(i);
                pair.add(n - i);
                ans.add(pair);
            }
        }

        return ans;
    }
}
