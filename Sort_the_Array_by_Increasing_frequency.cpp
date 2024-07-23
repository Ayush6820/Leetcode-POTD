/************************************************************ C++ ************************************************************/
//Approach-(Count frequencies and sort based on custom criteria)
//T.C : O(nlogn)
//S.C : O(k) where k is the number of unique elements in the array.
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        
        // Step 2: Sort the array with custom sorting logic
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (frequency[a] == frequency[b]) {
                return a > b;  // Sort by value in decreasing order if frequencies are the same
            }
            return frequency[a] < frequency[b];  // Sort by frequency in increasing order
        });
        
        return nums;
    }
};