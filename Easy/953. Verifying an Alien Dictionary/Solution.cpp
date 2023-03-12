class Solution {
public:

    bool isAlienSorted(vector<string>& words, string order) {
        int priority[26];
        for(int i = 0; i < 26; i++) // Create a priority for each letter based on the order string
            priority[order[i] - 'a' - 1] = i;

        vector<string> copy = words; // Take a copy from words

        sort(copy.begin(), copy.end(), [&](string &first, string &second) { // Sort them based on the priority
            int m1 = (int) first.size();
            int m2 = (int) second.size();

            for(int i = 0; i < m1; i++)
                if(first[i] != second[i]) // If the letters are not equal
                    return priority[first[i] - 'a'] < priority[second[i] - 'a']; // Less priority comes first

            return m1 <= m2; // If the letters are equal, then the shorter word comes first
        });

        return copy == words; // Return true if the sorted words are equal to the original words
    }
};