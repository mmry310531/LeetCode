class Solution {
public:
    
    //// main idea
    // 使用 ret = (target - nums[i]) 的剩餘值，尋找是否有被記錄
    // 如果有紀錄，則代表有解，回傳紀錄的index以及目前的index
    // 沒有紀錄則放入hash table, 提供下個 ret 收尋。
    

    // #hash table #unordered_map
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            int ret = target - nums[i];
            
            if(hash.find(ret) != hash.end()){
                ans.push_back(i);
                ans.push_back(hash[ret]);
                return ans;
            }
            
            hash[nums[i]] = i;
        }
        return ans;
    }
};