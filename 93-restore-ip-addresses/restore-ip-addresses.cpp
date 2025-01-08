class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.length();
        if (n < 4 || n > 12) return result;

        for (int i = 1; i < n && i < 4; ++i) {
            for (int j = i + 1; j < n && j < i + 4; ++j) {
                for (int k = j + 1; k < n && k < j + 4; ++k) {
                    string part1 = s.substr(0, i);
                    string part2 = s.substr(i, j - i);
                    string part3 = s.substr(j, k - j);
                    string part4 = s.substr(k);

                    if (isValid(part1) && isValid(part2) && isValid(part3) && isValid(part4)) {
                        result.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                    }
                }
            }
        }

        return result;
    }

    bool isValid(const string& part) {
        if (part.empty() || part.length() > 3) return false;
        if (part[0] == '0' && part.length() > 1) return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
};