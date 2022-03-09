class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        if (str.length() == 0)
            return true;
        for (char curr : str) {
            // Opening bracket
            if (opening_bracket(curr))
                s.push(curr);
            
            // Closing bracket
            else {
                if (s.empty())
                    return false;
                else {
                    char curr_top = s.top();
                    if (matching(curr_top, curr))
                        s.pop();
                    else
                        return false;
                }
            }
        }
        return s.empty();
    }
    
private:
    bool opening_bracket(char c) {
        return (c == '(' || c == '{' || c == '[');
    }
    
    bool matching (char opening, char closing) {
        return ( (opening == '(' && closing == ')')
              || (opening == '{' && closing == '}')
              || (opening == '[' && closing == ']')
               );
    }
};