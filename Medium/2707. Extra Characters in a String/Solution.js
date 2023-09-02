let dp;
const MX = 100;

var minExtraChar = function(s, dictionary) {
    dp = new Array(s.length);
    dp.fill(-1);
    return solve(s, dictionary, 0);
};

let solve = (s, dictionary, i) => {
    if(i >= s.length) return 0;

    let ret = dp[i];
    if(~ret) return ret;

    ret = MX;

    ret = Math.min(ret, solve(s, dictionary, i + 1) + 1);
    for(let idx = 0; idx < dictionary.length; idx++) {
        let word = dictionary[idx];
        const wordSize = word.length;
        const sub = s.substring(i, i + wordSize);
        if(sub == word)
            ret = Math.min(ret, solve(s, dictionary, i + wordSize));
    }

    return dp[i] = ret;
};