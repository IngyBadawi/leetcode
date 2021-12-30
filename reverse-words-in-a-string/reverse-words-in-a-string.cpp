class Solution {
public:
    string reverseWords(string s) {
        string prev = "";
        vector<string> words;
        string next;
        for (char c : s) {
            if (c == ' ') {
                if (prev.length())
                    words.push_back(prev);
                prev = "";
            }
            else {
                if (c != ' ')
                    prev += c;
            }
        }
        words.push_back(prev);
        reverse(words.begin(), words.end());
        string ret = "";
        for (int i = 0 ; i < words.size() ; i++) {
            if (words[i].length()) {
                ret += words[i];
                if (i != words.size() - 1)
                    ret += " ";
            }
        }
        return ret;
    }
};