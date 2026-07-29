class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        int small =nums[0];
        int large = nums[n];
        for(int i=small;i>0;i--){
            if(small%i==0 && large%i==0){
                return i;
            }
        }
        return 1;
    }
};