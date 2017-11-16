//unordered_map store sorted_string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, multiset<string>> map;
        for (string s : strs) {
            string t = strSort(s);
            map[t].insert(s);
        }
        for (auto m : map) {
            vector<string> anagram(m.second.begin(), m.second.end());
            result.push_back(anagram);
        }
        return result;
    }
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        int p = 0;
        string t(n, 'a');
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                t[p++] += i;
            }
        }
        return t;
    }
};
