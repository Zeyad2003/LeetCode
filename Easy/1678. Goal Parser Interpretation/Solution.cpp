class Solution {
public:
    string interpret(string command) {
        int n = (int) command.size();
        string ans;
        for(int i = 0; i < n; i++) {
            if(command[i] == 'G') { // add G
                ans.push_back('G');
            }
            else if(command[i] == '(' and command[i + 1] == ')') { // Add O
                ans.push_back('o');
                i++; // skip )
            } else { // Add al
                ans.push_back('a');
                ans.push_back('l');
                i += 3; // Skip al)
            }
        }
        return ans;
    }
};