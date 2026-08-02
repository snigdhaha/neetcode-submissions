class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        int base = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                base += customers[i];
        }

        int gain = 0;

        for (int i = 0; i < minutes; i++) {
            if (grumpy[i])
                gain += customers[i];
        }

        int maxGain = gain;

        for (int i = minutes; i < n; i++) {
            if (grumpy[i])
                gain += customers[i];

            if (grumpy[i - minutes])
                gain -= customers[i - minutes];

            maxGain = max(maxGain, gain);
        }

        return base + maxGain;
    }
};