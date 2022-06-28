class Solution {
public:
    
    //// main idea 
    //// 使用table紀錄美字母出現在 s string的位置。
    //// 每當 table[s[i]] 大於 length 的 start，代表重複須更新start
    //// 每個 loop 都需要更新table[s[i]] 的位置
    //// 256 是 ascii code 對應字母的數量 128 * 2(大小寫)
    int lengthOfLongestSubstring(string s) {
        vector<int> table(256,-1);
        int maxLength = 0;
        int start = -1;
        
        for(int i=0; i<s.length(); i++){
            if(table[s[i]] > start)
                start = table[s[i]];
                
            table[s[i]] = i;
            int length = i - start;
            maxLength = (maxLength > length) ? maxLength : length;
        }
        
        return maxLength;
    }
};