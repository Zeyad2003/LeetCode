class Solution {
    public static int upperBound(int[] arr, int left, int right, int key) {
        int mid, result = -1;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (arr[mid] <= key) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid - 1;
            }
        }

        return result;
    }

    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n = obstacles.length;
        int[] dp = new int[n];
        int[] ret = new int[n];

        int len = 0;
        for(int i = 0; i < n; i++){
            if(len == 0 || dp[len - 1] <= obstacles[i]){
                dp[len++] = obstacles[i];
                ret[i] = len;
            } else {
                int idx = upperBound(dp, 0, len - 1, obstacles[i]);
                dp[idx] = obstacles[i];
                ret[i] = idx + 1;
            }
        }

        return ret;
    }
}