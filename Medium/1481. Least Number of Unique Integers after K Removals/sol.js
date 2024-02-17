var findLeastNumOfUniqueInts = function(arr, k) {
    let mp = new Map();
    let freq = new MinPriorityQueue();

    for(let i of arr) {
        mp.set(i, mp.get(i) + 1 || 1);
    }

    for(let [key, value] of mp) {
        freq.enqueue(value);
    }

    while(!freq.isEmpty()) {
        let i = freq.front().element;
        if(k >= i) {
            k -= i;
            freq.dequeue();
        } else break;
    }

    return freq.size();
};