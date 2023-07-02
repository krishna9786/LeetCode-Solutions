class Solution {
public:
   int sumImbalanceNumbers(vector<int>& A) {
    int res = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        //create unsorted array
        unordered_set<int> s;
        //insert ele one by one
        s.insert(A[i]); 
        //to store curr imbalance
        int cur = 0; 
        for (int j = i + 1; j < n; ++j) {
            //if element is not present
            if (s.count(A[j]) == 0) { 
               //check if the adj ele are present or not
                cur += 1 - s.count(A[j] + 1) - s.count(A[j] - 1);
            }
            //enter current ele into the set
            s.insert(A[j]);
            //add the current element into the res 
            res += cur; 
        }
    }
    return res;
}

};
