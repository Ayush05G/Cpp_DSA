class Solution {
public:
string reverseEquation(string s) {
    // Stack to store numbers and variables
    stack<string> stk;

    // Temporary variables to store current number or variable
    string current = "";

    // Iterate through the string
    for (char c : s) {
        if (isalnum(c)) {
            // Append alphanumeric characters to current variable
            current += c;
        } else {
            if (!current.empty()) {
                // Push the current variable to the stack
                stk.push(current);
                current = "";
            }
            // Push the operator to the stack
            stk.push(string(1, c));
        }
    }

    // Push the last variable to the stack
    if (!current.empty()) {
        stk.push(current);
    }

    // Reconstruct the reversed equation
    string result = "";
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return result;
}
};