class MedianFinder {
public:
    priority_queue<int> maxHeap; // Stores the smaller half of the numbers in descending order
    priority_queue<int, vector<int>, greater<> > minHeap; // Store the larger half of the numbers in ascending order

    MedianFinder() {}

    void addNum(int num) {
        minHeap.emplace(num); // push to minHeap
        if((int) maxHeap.size() + 1 < (int) minHeap.size()) { // Equalize the size of both heaps
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }

        while(!minHeap.empty() and !maxHeap.empty() and minHeap.top() < maxHeap.top()) { // Put the elements in the correct heap
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if ((int) maxHeap.size() == (int) minHeap.size()) { // If equal size -> average of the top elements in the 2 heaps
            double val = maxHeap.top() + minHeap.top();
            return val / 2;
        } else { // Else -> The top in the heap with larger size
            if ((int) maxHeap.size() > (int) minHeap.size()) return maxHeap.top();
            else return minHeap.top();
        }
    }
};