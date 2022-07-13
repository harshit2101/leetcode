class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> curr;
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        backtrack(ans, curr, nums, 0);
        ret.assign(ans.begin(), ans.end());
        return ret;
    }
    void backtrack(set<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int pos) {
        if(pos == nums.size()) {
            ans.insert(curr);
            return;
        }
        curr.push_back(nums[pos]);
        backtrack(ans, curr, nums, pos + 1);
        curr.pop_back();
        backtrack(ans, curr, nums, pos + 1);
    }
};