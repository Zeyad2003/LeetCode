var minOperations = function(nums, k) {
    let distinctNums = new Set();
    distinctNums.add(k);

    let minNum = nums[0];

    for(let i = 0; i < nums.length; i++) {
        minNum = Math.min(minNum, nums[i]);
        distinctNums.add(nums[i]);
    }

    if(k > minNum) return -1;
    return distinctNums.size - 1;
};
