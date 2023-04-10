class KthLargest {
public:
    int k; // kth largest
    priority_queue<int, vector<int>, greater<>> pq; // Min Heap

    KthLargest(int k, vector<int>& nums) {
        for(auto & i : nums) pq.emplace(i); // Add all elements to min heap
        this->k = k; // Store k
    }

    int add(int val) {
        pq.emplace(val); // Add new element to min heap
        while(pq.size() > k) pq.pop(); // Remove all elements except kth largest
        return pq.top(); // Return kth largest
    }
};