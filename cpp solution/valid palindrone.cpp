class Solution {
    bool is_valid(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return true;
        }
        return false;
    }
    char toLowercase(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return ch;
        }
        else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool is_palindrone(string S){
        int start = 0;
        int end = S.size() - 1;
        while (start < end){
            if (S[start] != S[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    bool isPalindrome(string S) {
        string desired_str = "";
        for (auto ch: S){
            if (is_valid(ch)){
                desired_str += toLowercase(ch);
            }
        }
        bool result = is_palindrone(desired_str);
        return result;
    }
};
