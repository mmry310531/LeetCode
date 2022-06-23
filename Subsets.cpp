class Solution {
public:
    void dp(vector<int>&ref, vector<vector<int>>&ans, vector<int>& curVec, int depth, int cur){
        if(cur>=depth) return;
        
        curVec.push_back(ref[cur]);
        dp(ref, ans, curVec, depth, cur+1);
        ans.push_back(curVec);
        curVec.pop_back();
        dp(ref, ans, curVec, depth, cur+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> empty;
        vector<vector<int>> ans;
        vector<int> curVec;
        int depth = nums.size();
        int cur = 0;
        
        dp(nums, ans, curVec, depth, cur);
        ans.push_back(empty);
        return ans;
    }
};