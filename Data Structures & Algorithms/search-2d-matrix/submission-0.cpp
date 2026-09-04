class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) 
            return false;
        int low = 0, high = n - 1, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][m - 1])
                break;
            else if (target < matrix[mid][0])
                high = mid - 1;
            else if (target > matrix[mid][m - 1])
                low = mid + 1;
        }
        low = 0;
        high = m - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (target == matrix[mid][middle]) return true;
            if (target > matrix[mid][middle]) low = middle + 1;
            if (target < matrix[mid][middle]) high = middle - 1;
        }
        return false;
    }
};
