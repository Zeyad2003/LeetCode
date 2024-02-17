class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Integer> freq = new PriorityQueue<>();

        for(int i : arr) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        for(int i : mp.values()) freq.add(i);

        while(!freq.isEmpty()) {
            int i = freq.peek();
            if(k >= i) {
                k -= i;
                freq.poll();
            } else break;
        }

        return freq.size();
    }
}