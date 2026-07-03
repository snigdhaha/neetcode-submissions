class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;
        int n=gas.size();

        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }

        if(totalGas<totalCost) return -1;

        int tank=0;
        int res=0;
        for(int i=0;i<n;i++){
            tank+=(gas[i]-cost[i]);

            if(tank<0) {
                tank=0;
                res=i+1;
            }
        }
        return res;
    }
};
