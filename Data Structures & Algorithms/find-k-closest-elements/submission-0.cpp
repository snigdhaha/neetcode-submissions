class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans;
        int l=0;
        int r=n-1;
        while(r-l>=k){
            if(abs(arr[l]-x) < abs(arr[r]-x)){
                r--;
            }
            else if( abs(arr[l]-x) > abs(arr[r]-x)){
                l++;
            }
            else{
                //if they are equal move either of them
                r--;
            }
        }
        ans.insert(ans.end(), arr.begin() + l, arr.begin() + r + 1);
        return ans;
    }
};