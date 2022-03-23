class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int ansIndex = 0;
        int currIndex = 0;
        while (currIndex < n){
            int repeatingIndex = currIndex + 1;
            // keep moving repeating character until we get different character
            while (repeatingIndex < n && chars[repeatingIndex] == chars[currIndex]){
                repeatingIndex++;
            }
            // store the old character
            chars[ansIndex++] = chars[currIndex];
            int repeatingCharCount = repeatingIndex -  currIndex;
            // convert count into string and modify chars array with each 'count char'
            if (repeatingCharCount > 1){
                string count = to_string(repeatingCharCount);
                for (auto ch: count){
                    chars[ansIndex++] = ch;
                }
            }
            currIndex = repeatingIndex;
        }
        return ansIndex;
    }
};
