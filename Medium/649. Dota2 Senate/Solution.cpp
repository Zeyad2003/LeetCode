class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int n = (int) senate.size();

        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') R.emplace(i);
            else D.emplace(i);
        }

        while(!D.empty() and !R.empty()) {
            int r = R.front(), d = D.front();
            R.pop(), D.pop();
            if(r < d) R.emplace(r + n);
            else D.emplace(d + n);
        }

        return R.empty() ? "Dire" : "Radiant";
    }
};