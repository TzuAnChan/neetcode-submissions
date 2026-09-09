class Solution {
public:
    bool isAlphanumeric(const char& c) {
        if ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') || 
            (c >= '0' && c <= '9')) {
                return true;
            }

        return false;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.length();
        while (l < r) {
            while(l < r && !isAlphanumeric(s[l])) l++;
            while(l < r && !isAlphanumeric(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
};
