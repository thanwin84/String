//method: pick or not pick by recursion
public:
    void solve(string str, string outputSoFar) {
        if (str.size() == 0) {
            cout << outputSoFar << endl;
            return;
        }
        // we choose to include the first character
        solve(str.substr(1), outputSoFar + str[0]);
        // we don't choose to include the first character
        solve(str.substr(1), outputSoFar);
    }
    void print_all_subsequence(string str) {
        solve(str, "");
    }
};
// time: O(n*2^n) cause we have 2^n recursion state and at each recursion we are creating new copy string of original array
//iterative approach
class Solution {
public:
    void print_all_subsequence(string str) {
        vector<string> output;
        for (auto i : str) {
            vector<string> copy;
            string temp = "";
            copy.push_back(temp + i);
            for (auto item: output) {
                copy.push_back(item + i);
            }
            for (auto item : copy) {
                output.push_back(item);
            }
        }
        for (auto item : output) {
            cout << item << " ";
        }
        
    }
};
// same time complexity but we are using extra space here which O(n*2^n)
