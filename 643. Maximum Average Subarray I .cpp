class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int leftIdx = 0;
        int rightIdx = k;

        int curVal = 0;
        for(int i=0;i<k;i++){
            curVal += nums[i];
        }

        int maxVal = curVal;

        for(int i = k; i < nums.size(); i++){
            curVal += (nums[rightIdx] - nums[leftIdx]);
            maxVal = max(maxVal, curVal);
            leftIdx++;
            rightIdx++;
        }

        return ((double)maxVal / k);
        
    }
};