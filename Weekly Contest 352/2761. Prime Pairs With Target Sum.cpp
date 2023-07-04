class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        //first calculate the prime  number
       vector <bool> prime(n+1, 1);
        for(int i = 2; i <= n; i++) {
            if(prime[i] == 0) continue;
            for(int j = 2*i; j <= n; j+=i) {
                prime[j] = 0;
            }
        }
        
        //iterate and find the pair whose sum is equal to n
        vector<vector<int>> ans;
        for(int i = 2; 2*i <= n; i++) {
            if(prime[i] == 1 && prime[n-i] == 1) ans.push_back({i, n-i});
        }
        
        return ans;
    }
};
