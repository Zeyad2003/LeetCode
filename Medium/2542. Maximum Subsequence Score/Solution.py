def compare_max(a, b):
    return b - a

class Solution(object):
    def maxScore(self, nums1, nums2, k):
        n = len(nums1)
        v = []
        for i in range(n):
            v.append((nums2[i], nums1[i]))
        v.sort(reverse = True)

        pq = []
        sum = 0
        ans = 0

        for i in range(k - 1):
            heapq.heappush(pq, v[i][1])
            sum += v[i][1]

        for i in range(k - 1, n):
            sum += v[i][1]
            heapq.heappush(pq, v[i][1])
            ans = max(ans, sum * v[i][0])

            sum -= heapq.heappop(pq)

        return ans