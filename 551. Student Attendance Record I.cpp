class Solution {
public:
    bool checkRecord(string s) {
        int lateSCount = 0;
        int absentCount = 0;

        for(auto c : s){
            if(c=='A'){
                absentCount++;
                if(absentCount >= 2)
                    return false;
                
            }
            if(c=='L'){
                lateSCount++;
                if(lateSCount >= 3)
                    return false;
            }
            else{
                lateSCount = 0;
            }
        }
        return true;

    }
};