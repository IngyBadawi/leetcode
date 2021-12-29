class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int len = n << 1;
        int possible_combinations = (1 << (len - 1));
        for (int  i = 0 ; i < possible_combinations ; i++) {
            string curr = create_parenthesis(i, len);
            if (valid_parenthesis(curr)) {
                ans.push_back(curr);
            }
        }
        return ans;
    }
private:
    string create_parenthesis(int curr, int len) {
        string parenthesis = "";
        for (int i = len - 1 ; i >= 0 ; i--) {
            if (curr & (1 << i))
                parenthesis += ')';
            else
                parenthesis += '(';
        }
        return parenthesis;
    }
    
    bool valid_parenthesis(string parenthesis) {
        if (parenthesis.length() == 0)
            return true;
        stack <char> s;
        for (int i = 0 ; i < parenthesis.length() ; i++) {
            if (opening(parenthesis[i]))
                s.push(parenthesis[i]);
            else {
                if (s.empty())
                    return false;
                else
                    s.pop();
            }
        }
        return s.empty();
    }
    
    bool opening (char c) {
        return c == '(';
    }
    
};