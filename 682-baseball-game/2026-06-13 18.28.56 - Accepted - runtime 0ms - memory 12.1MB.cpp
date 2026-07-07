class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string op : operations) {
            if(op == "C") st.pop();
            else if(op == "D") {
                if(st.size() > 0) st.push(2 * st.top());
                else return 0;
            }
            else if(op == "+") {
                if(st.size() >= 2) {
                    int first = st.top();
                    st.pop();

                    int second = st.top();
                    st.push(first);
                    st.push(first + second);
                }
            }
            else {
                int x = stoi(op);
                st.push(x);
            }
        }

        int sum = 0;
        while(!st.empty()) {
            int t = st.top();
            sum += t;
            st.pop();
        }

        return sum;
    }
};