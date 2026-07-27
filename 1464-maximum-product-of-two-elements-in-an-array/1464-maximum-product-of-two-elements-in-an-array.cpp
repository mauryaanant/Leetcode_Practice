class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size();j++){
                int f= nums[i]-1;
                int s= nums[j]-1;
                int prod = (f*s);
                if(prod>max){
                    max=prod;
                }
            }

        }

        return max;
    }
};