class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high) {
            // Calculate the middle index of the virtual 1D array
            int mid = (low + high) / 2;

            // Convert mid index to corresponding 2D indices
            int row = mid / m;
            int col = mid % m;

            // Check if the target is found
            if (matrix[row][col] == target)
                return true;

            // If the target is greater, discard the left half
            else if (matrix[row][col] < target)
                low = mid + 1;

            // If the target is smaller, discard the right half
            else
                high = mid - 1;
        }

        // If not found, return false
        return false;
    
    }
};
