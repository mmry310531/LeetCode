class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mapLHS;

        for(auto i : nums)
            mapLHS[i]++;


        int maxLength = 0;
        for(auto [index, count] : mapLHS){
            if(mapLHS.find(index+1) != mapLHS.end()){
                maxLength = max(maxLength, (count+mapLHS[index+1]));
            }
        }
        return maxLength;
    }
};