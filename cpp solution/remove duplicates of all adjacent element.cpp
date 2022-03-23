// time and space: O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;
        int start = 0;
        int end = s.size();
        while (start < end){
            if (stack.size() == 0){
                stack.push_back(s[start]);
            }
            else {
                if (s[start] == stack.back()){
                    stack.pop_back();
                }
                else {
                    stack.push_back(s[start]);
                }
            }
            start++;
        }
        string unique_s = "";
        for (auto i: stack){
            unique_s += i;
        }
        return unique_s;
    }
};
