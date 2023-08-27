class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0;
        int i = 1;
        set<int> s;

        while(n) {
            if(s.find(i) == s.end()) {
                s.insert(target - i);
                ans += i;
                n--;
            }
            i++;
        }
        return ans;
    }
};
