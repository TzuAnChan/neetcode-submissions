class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const string& str: strs) {
            int length = str.length();
            encoded.append(to_string(length));
            encoded.push_back('#');
            encoded.append(str);
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        int n = s.length();
        while(i < n) {
            int pound_pos = s.find('#', i);
            int length = stoi(s.substr(i, pound_pos - i));
            int str_start = pound_pos + 1;
            string sub = s.substr(str_start, length);
            decoded.push_back(sub);
            i = str_start + length;
        }

        return decoded;
    }
};
