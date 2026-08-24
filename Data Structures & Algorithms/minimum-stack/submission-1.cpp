class MinStack {
   public:
    stack<int> l;
    stack<int> minE;
    MinStack() {}

    void push(int val) {
        l.push(val);
        if (minE.empty())
            minE.push(val);
        else if (minE.top() >= val)
            minE.push(val);
    }

    void pop() {
        if (l.top() == minE.top()) minE.pop();
        l.pop();
    }

    int top() { return l.top(); }

    int getMin() { return minE.top(); }
};
