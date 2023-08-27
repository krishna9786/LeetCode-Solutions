/*
Author: darkflameace97

Explanation:
- Given a string of 'L', 'R', and 'U' characters, we need to find the furthest distance from the origin (0, 0).
- We count the number of 'L', 'R', and 'U' characters in the string.
- The furthest distance from the origin can be achieved by:
    - Moving to the left ('L') if there are more 'L' characters than 'R'.
    - Moving to the right ('R') if there are more 'R' characters than 'L'.
    - Moving vertically ('U') if the counts of 'L' and 'R' are equal.
- We calculate the final distance based on the above conditions and return it as the answer.
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n = s.size();
        int l = 0, r = 0, d = 0;
        int ans = 0;
        
        // Count the occurrences of 'L', 'R', and 'U' characters
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') l++;
            else if (s[i] == 'R') r++;
            else d++;
        }
        
        // Calculate the furthest distance based on character counts
        if (l > r) {
            ans += l + d - r;
        } else if (r > l) {
            ans += r + d - l;
        } else {
            ans += d;
        }
        
        return ans;
    }
};
