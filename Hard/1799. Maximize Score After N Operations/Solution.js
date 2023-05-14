let n, dp;

var gcd = (a, b) => {
    if(b == 0) return a;
    return gcd(b, a % b);
}

var solve = function(arr, mask, i) {
    if(i > n) return 0;

    if(dp[mask][i] != -1) return dp[mask][i];

    let ret = 0;

    for(let bt1 = 0; bt1 < (n << 1); bt1++) {
        for(let bt2 = bt1 + 1; bt2 < (n << 1); bt2++) {
            let firstPlace = (mask & (1 << bt1));
            let secondPlace = (mask & (1 << bt2));
            if(firstPlace != 0 && secondPlace != 0)
                ret = Math.max(ret, i * gcd(arr[bt1], arr[bt2]) + solve(arr, mask & ~(1 << bt1) & ~(1 << bt2), i + 1));
        }
    }

    return dp[mask][i] = ret;
}

var maxScore = function(nums) {
    n = nums.length;
    dp = Array.from({ length: 1 << n }, () => Array(8).fill(-1));

    let mask = (1 << n) - 1;
    n >>= 1;
    return solve(nums, mask, 1);
};