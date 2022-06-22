class Solution {
public:
    ////// main idea //////
    // Select one value from INT_MIN to INT_MAX and check if it's larger than element
    // Numbers of elements is k_
    // k_ >= kth => move left to middle, there may answer here.
    // k_ < kth => move right to middle-1
    
    // binaray search
    int findKthLargest(vector<int>& nums, int k) {
        int left=INT_MIN/2; int right=INT_MAX/2;
        
        
        while(left<right){
        
            // choose middle point as pivot
            int mid = right - (right-left)/2;
            
            // change left as middle to find kth largest element 
            if(count(nums, mid) >= k){
                left = mid;
            }
            // change right as middle-1, count number will be larger
            else{
                right = mid-1;
            }
        }

        return left;
    }
    
    // count numbers of element (int nums) larger than k 
    // if numbers larger than kth move "left" 
    // if numbers less than kth move "right"
    int count(vector<int> &nums, int k){
        int ret = 0;
        for(auto i : nums){
            ret += i>=k;
        }
        
        return ret;
    }
};