class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];

            //ch -> open/close bracket
            //open ->  sirf push krta hu
            //close -> isme check krta hu k same type ka open h ya nahi

            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                //mujhe close bracket mila h 
                //close bracket k case me 
                //main stack k top pr jata hu and check krta hu
                //k mujhe same type ka open bracket mila ya nahi 
                if(ch == ')' && !st.empty() && st.top() == '(') {
                    //bracket match -> cancel out 
                    st.pop();
                }
                else if(ch == ']' && !st.empty() && st.top() == '[') {
                    //bracket match
                    st.pop();
                }
                else if(ch == '}' && !st.empty() && st.top() == '{') {
                    //bracket match
                    st.pop();
                }
                else {
                    //bracket not-match
                    return false;
                }
            }
        }
        //check stack ka size here 
        if(st.size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};