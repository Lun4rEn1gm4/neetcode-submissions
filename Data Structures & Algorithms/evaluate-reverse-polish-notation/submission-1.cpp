class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> a;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int temp=a.top(); a.pop();
                int x = a.top()+temp; a.pop();
                a.push(x); 
            }
            else if(tokens[i]=="-"){
                int temp=a.top(); a.pop();
                int x = a.top()-temp; a.pop();
                a.push(x); 
            }
            else if(tokens[i]=="*"){
                int temp=a.top(); a.pop();
                int x = a.top()*temp; a.pop();
                a.push(x); 
            }
            else if(tokens[i]=="/"){
                int temp=a.top(); a.pop();
                int x = a.top()/temp; a.pop();
                a.push(x); 
            }
            else {
                a.push(stoi(tokens[i]));
            }
        }
        return a.top();
    }
};
