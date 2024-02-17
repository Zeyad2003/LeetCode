class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        mp = {}
        freq = []

        for i in arr:
            if i in mp: mp[i] += 1
            else: mp[i] = 1

        for i in mp: freq.append(mp[i])

        freq.sort()

        while freq:
            i = freq[0]
            if k >= i:
                k -= i
                freq.pop(0)
            else:
                break

        return len(freq)
       