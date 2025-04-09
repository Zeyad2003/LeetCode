class Solution {
    public int minOperations(int[] nums, int k) {
        HashSet<Integer> distinctNums = new HashSet<>();
        distinctNums.add(k);

        Integer minNum = nums[0];

        for (int i = 0; i < nums.length; i++) {
            minNum = Math.min(minNum, nums[i]);
            distinctNums.add(nums[i]);
        }

        if (k > minNum) return -1;
        return distinctNums.size() - 1;
    }
}
