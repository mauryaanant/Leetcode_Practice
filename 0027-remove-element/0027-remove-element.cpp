class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count =0;
        int k=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]!=val){
                count++;
                nums[k]=nums[i];
                k++;
            }
        }

        return count;
    }
};