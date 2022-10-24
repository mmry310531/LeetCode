class Solution {
public:

    void reverseOneWord(string &s, int startIdx, int endIdx){

        for(int i=0;i<(endIdx-startIdx)/2+1;i++){
            char c = s[startIdx+i];
            s[startIdx+i] = s[endIdx-i];
            s[endIdx-i] = c;
        }
    }
    string reverseWords(string s) {
        int startIdx = 0;
        int endIdx = 0;

        for(int i=0;i<s.length();i++){


            if(s[i] == ' '){
                // character before space
                int endIdx = i - 1;
                reverseOneWord(s, startIdx, endIdx);
                // character after space
                startIdx = (i + 1);
                
            }
            if(i==(s.length()-1)){
                reverseOneWord(s, startIdx, i);
            }
        }
        return s;
    }
};