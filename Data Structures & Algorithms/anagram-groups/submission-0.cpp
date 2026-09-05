class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ump;

        for (const string& str : strs) {
            string count(26, '0');
            for (const char& c: str) {
                count[c - 'a']++;
            }

            ump[count].push_back(str);
        }

        for (const auto& it: ump) {
            result.push_back(it.second);
        }

        return result;
    }
};
