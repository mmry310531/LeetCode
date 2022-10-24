class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> list1_map;
        vector<string> ans;

        for(int i=0; i<list1.size(); i++){
            list1_map[list1[i]] = i;
        }

        int minLength = INT_MAX;
        for(int i=0; i<list2.size();i++){
            if(list1_map.find(list2[i]) != list1_map.end()){
                if( (list1_map[list2[i]] + i) < minLength){
                    minLength = (list1_map[list2[i]] + i);
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if ( (list1_map[list2[i]] + i) == minLength){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;


    }
};