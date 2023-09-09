let dp = [];

let solve = (nums, target, val) => {
    if (val > target)
            return 0;
        if (val == target)
            return 1;

        if (dp[val] != -1)
            return dp[val];

        let ret = 0;
        for (const it of nums)
            ret += solve(nums, target, val + it);
        return dp[val] = ret;
};

var combinationSum4 = function(nums, target) {
    dp = new Array(target).fill(-1);
    return solve(nums, target, 0);
};