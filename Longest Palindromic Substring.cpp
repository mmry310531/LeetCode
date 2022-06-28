class Solution {
public:
    string longestPalindrome(string s) {
        
        
        
        //// main idea
        //// 不能使用reverse， 可能會有 abc de cba 的情況發生
        //// 最佳解複雜度為O(n^2), 巡邏每個字，並看左右兩邊是否有相同
        
        
        if(s.length() < 2) return s;
        
        int L = -1;
        int max_length = -1;
        int test = 0;
        for(int idx = 0; idx<s.length(); idx++){
            // std::cout << "idx : " << idx << std::endl;
            
            int right = idx, left = idx;
            while(s[idx]==s[idx+1]) {
                right++;
                idx++;
            }
            
            
            
            
            
            while(right<s.length()-1 && left >0 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            
            // std::cout << "left : "  << left<< std::endl;
            // std::cout << "right : " << right << std::endl;
            
            if(max_length < (right-left+1)){
                max_length = (right-left+1);
                L = left;
            }
            
            test = idx;
            
            
        }
        return s.substr(L,max_length);
    }
};