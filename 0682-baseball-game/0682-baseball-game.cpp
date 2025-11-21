class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;

        for(int i =0 ; i<operations.size(); i++){
            if(operations[i] == "C"){
                st.pop();
            }else if(operations[i] == "D"){
                int x = 2 * st.top();
                st.push(x);
            }else if(operations[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }else{
                st.push(stoi(operations[i]));
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};