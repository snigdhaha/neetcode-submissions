class Solution {
public:
    int calculateTotalHours(vector<int>& piles, int speed) {
        int totalH = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalH += ceil((double)piles[i] / speed);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        int low = 1, high = maxPile;
        int ans = maxPile;

        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(piles, mid);

            // If possible, try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
