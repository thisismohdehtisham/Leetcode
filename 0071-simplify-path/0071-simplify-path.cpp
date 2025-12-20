class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string token = "";
        stringstream ss(path);

        while(getline(ss, token, '/')){
            if(token == "" || token == ".") continue;

            if(token != ".."){
                st.push(token);
            }else if(!st.empty()){
                st.pop();
            }
        }
            string res = "";
            while(!st.empty()){
                res = "/" + st.top() + res;
                st.pop();
            }
            if(res.length() == 0) res = "/";

            return res;
        
    }
};