class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto & i : stones) q.emplace(i);

        while((int) q.size() > 1) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(x == y) continue;
            else q.emplace(y - x);
        }

        if(!q.empty()) return q.top();
        else return 0;
    }
};