class Solution {
public:
    vector<int> solve(string s) {
        vector<int> result;

        // Iterate through the string to find operators
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                // Recursively solve for left and right parts of the expression
                vector<int> left_results  = solve(s.substr(0, i));
                vector<int> right_results = solve(s.substr(i+1));

                // Compute all combinations of left and right results based on the operator
                for(int &x : left_results) {
                    for(int &y : right_results) {
                        if(s[i] == '+') {
                            result.push_back(x + y);
                        } else if(s[i] == '-') {
                            result.push_back(x - y);
                        } else if(s[i] == '*') {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }

        // If no operators are found, convert the string to an integer and add to the result
        if(result.empty()) {
            result.push_back(stoi(s));
        }
        return result;
    }

    vector<int> diffWaysToCompute(string s) {
        // Simply call the solve function
        return solve(s);
    }
};
