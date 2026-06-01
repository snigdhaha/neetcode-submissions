class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

    int left=0;
    int right=n-1;

    int maxL=0;
    int maxR=0;

    int total=0;

    while(left<=right){
        //if left bar is smaller or equal to right bar
        if(height[left]<=height[right]){
            //if curr left bar is higher than maxleft, update maxleft
            if(height[left]>=maxL){
                maxL=height[left];
            }
            else{
                //water trapped on left is-
                total += maxL-height[left];
            }
            left++;
        }
        else{
            //if current right bar is greater then max right
            if(height[right]>=maxR){
                maxR=height[right];

            }
            else{
                total+=maxR-height[right];
            }
            right--;

        }
    }

    return total;
    }
};
