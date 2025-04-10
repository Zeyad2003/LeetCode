var rob = function(nums) {
    let sz = nums.length;
    let dp = new Array(101).fill(-1);
    
    const solve = (i) => {
        if (i >= sz) return 0;
        if (dp[i] !== -1) return dp[i];
        return dp[i] = Math.max(solve(i + 1), nums[i] + solve(i + 2));
    };

    return solve(0);
};
