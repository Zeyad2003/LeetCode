class Solution(object):

    def can(self, dist, hour, mid):
        ret = 0.0
        for i in range(len(dist) - 1):
            ret += math.ceil(dist[i] / mid)
        ret += dist[-1] / mid
        return ret <= hour

    def minSpeedOnTime(self, dist, hour):
        oo = 10**7 + 5
        l, r, ans = 1, oo, oo
        while l <= r:
            mid = (l + r) // 2
            if self.can(dist, hour, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans if ans < oo else -1