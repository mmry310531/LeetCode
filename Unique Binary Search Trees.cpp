class Solution {
public:
    
    
    //// main idea
    //// DP問題，n從小到大開始堆疊。
    //// 假設題目為n 我們知道k-1 以及(n-k)的結果，只需要把兩邊相乘即為n的答案
    //// 而選擇k為root只是n結構的一部分。我們必須選取不同的node當作root累加做結果
    
    //// level 由小到大
    //// root選取不同累加結果
    
    int numTrees(int n) {
        vector<int> dp(50,0);
        dp[0] = dp[1] = 1;
        
        
        for(int level=2;level<=n;level++){
            for(int root = 1; root <= level; root++){
                int left = root-1;
                int right = (level-root);
                dp[level] += dp[left] * dp[right];
            }
        }
        
        return dp[n];
    }
};