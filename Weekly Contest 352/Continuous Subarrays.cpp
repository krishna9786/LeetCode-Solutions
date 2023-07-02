class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        //create a multiset
        multiset <int> s;
        long long ans = 0;
        
        int j = 0;
        //iterate and insert into the multiset
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            while(*s.rbegin() - *s.begin() > 2) s.erase(s.find(nums[j++]));
            
            ans += i - j + 1;
        }
        
        return ans;
    }
};
