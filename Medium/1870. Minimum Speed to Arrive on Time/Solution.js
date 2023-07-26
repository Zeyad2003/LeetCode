let oo = 1e7 + 5;

let can = (dist, hour, speed) => {
    let ret = 0.0, n = dist.length;
    for(let i = 0; i < n - 1; i++)
        ret += Math.ceil(dist[i] / speed);

    ret += dist[n - 1] / speed;
    return ret <= hour;
}

var minSpeedOnTime = function(dist, hour) {
    let l = 1, r = oo, ans = oo, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        mid = parseInt(mid);
        if(can(dist, hour, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    ans = parseInt(ans);
    return ans == oo ? -1 : ans;
};