class Solution:
    def findPrimePairs(self, n: int) -> List[List[int]]:
        # First calculate the prime numbers
        prime = [True] * (n + 1)
        prime[0] = prime[1] = False

        for i in range(2, n + 1):
            if prime[i]:
                for j in range(2 * i, n + 1, i):
                    prime[j] = False

        # Iterate and find the pairs whose sum is equal to n
        ans = []
        for i in range(2, n // 2 + 1):
            if prime[i] and prime[n - i]:
                ans.append([i, n - i])

        return ans
