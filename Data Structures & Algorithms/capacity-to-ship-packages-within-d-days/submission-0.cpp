class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity){
    //initialize count of days to 1 (start w day 1)
    int days=1;

    int currentLoad=0;

    for(int i=0;i<weights.size();i++){
        int w=weights[i];

        //check if adding package exceeds ship capacity for the day
        if(currentLoad + w > capacity){
            days++;
            //start new day's load with current package weight
            currentLoad = w;
        }else{
            //if it doesnt exceed add current weight to the load
            currentLoad+=w;
        }
    }
    return days;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
       

        while(low<=high){
            int mid=(low+high)/2;
            //calculate how many days needed if ship capacity is mid
        int needed = daysNeeded(weights,mid);

        if(needed<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return low;

    }
};