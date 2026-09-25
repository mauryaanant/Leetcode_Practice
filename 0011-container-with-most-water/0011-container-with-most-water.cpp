class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right= height.size()-1;
        int maxarea=0;
        

        while(left<right){ 
            int length = min(height[left], height[right]);
            int breadth = right - left;
            int area = length * breadth;
            maxarea = max(area, maxarea);

            if(height[left]< height[right]){
                left++;
            }else{
                right--;
            }
        }

        // for(int i=0;i<n;i++){

        //     for(int j=i+1;j<n;j++){
        //         int length = min(height[i],height[j]);
        //         int breadth = j-i;

        //         int area=length*breadth;

        //         maxarea=max(maxarea , area);

        //     }
        // }

        return maxarea;
    }


};