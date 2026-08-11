class Solution {
   public:
    bool isValid(string s) {
        stack<char> res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                res.push(s[i]);
            else {
                if (!res.empty()) {
                    if (s[i] == ')' && res.top() == '(')
                        res.pop();
                    else if (s[i] == '}' && res.top() == '{')
                        res.pop();
                    else if (s[i] == ']' && res.top() == '[')
                        res.pop();
                    else
                        return false;

                } else {
                    return false;
                }
            }
        }
        return res.empty();
    }
};
