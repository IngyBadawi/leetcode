class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        int cnt = 0; 
        for(int i = 0 ; i < n ; i++) {
            if (!is_bracket(s[i]))
                continue;
            
            if(opening_bracket(s[i])) {
                cnt++;
            }
            else {
                if (cnt == 0) {
                    s[i] = '#';
                }
                else {
                    cnt--;
                }
            }
        }
        
        cnt = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            if (!is_bracket(s[i]))
                continue;
            
            if (opening_bracket(s[i])) {
                if(cnt == 0) { 
                    s[i] = '#';
                }
                else{
                    cnt--;
                }
            }
            else {
                cnt++;
            }
        }
        
        string ans="";
        for (int i = 0 ; i < n ; i++) {
            if(s[i] != '#'){ 
                ans += s[i];
            }
        }
        
        return ans;
    }
    
private:
    bool is_bracket(char c) {
        return (c == '(' || c == ')');
    }
    
    bool opening_bracket(char c) {
        return (c == '(');
    }
};