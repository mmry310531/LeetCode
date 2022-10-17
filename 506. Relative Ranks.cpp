class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        // priority queue :
        //      first : score, second : order in array
        string FirstRank = "Gold Medal";
        string SecondRank = "Silver Medal";
        string ThirdRank = "Bronze Medal";
        priority_queue<pair<int, int>> pq;

        for(int i=0;i<score.size();++i){
            pq.push(make_pair(score[i], i));
        }

        vector<string> ans(score.size(), "");
        
        int count = 1;
        while(!pq.empty()){
            auto res = pq.top();

            if(count==1) ans[res.second] = (FirstRank);
            else if(count == 2) ans[res.second] = (SecondRank);
            else if(count == 3) ans[res.second] = (ThirdRank);
            else ans[res.second] = to_string(count);
            ++count;

            pq.pop();
        }

        return ans;
        
    }
};