class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        vector<int> ans(n);
        long long avg=0;
        long long t=1;

        for(int i=0;i<n;i++){
            int arrival=customers[i][0];
            int time=customers[i][1];
            t = max(t, (long long)arrival);
            t += time;
            int wt=t-arrival;
            ans[i]=wt;
        }

        for(int i=0;i<n;i++){
            avg+=ans[i];
        }
        
        return (double)avg / n;;
    }   
};