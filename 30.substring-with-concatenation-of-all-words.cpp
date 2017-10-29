/*Use an unordered_map<string, int> counts to record the expected times of each word and another unordered_map<string, int> seen to record the times we have seen. Then we check for every possible position of i. Once we meet an unexpected word or the times of some word is larger than its expected times, we stop the check. If we finish the check successfully, push i to the results.*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words) {
            counts[word]++;
        }
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> results;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                } else break;
            }
            if (j == num) results.push_back(i);
        }
        return results;
    }
};
