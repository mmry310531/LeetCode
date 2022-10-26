class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> FEN_map;

        for(auto i : nums){
            FEN_map[i]++;
        }
        int missNum = -1;
        int wrongNum = -1;
        for(int i=0;i<nums.size();i++){
            if(FEN_map.find((i+1)) == FEN_map.end()){
                missNum = (i+1);
            }

            else if(FEN_map[(i+1)] == 2){
                wrongNum = (i+1);
            }
        }

        vector<int> ans;
        ans.push_back(wrongNum);
        ans.push_back(missNum);

        return ans;
    }
};