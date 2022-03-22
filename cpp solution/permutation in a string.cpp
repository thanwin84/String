// time: O(l1 + 26*(l2-l1) and space: O(1)
class Solution {
    bool checkEqual(vector<int> &count1, vector<int> &count2){
        for (int i = 0; i < 26; i++){
            if (count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0), count2(26, 0);
        // storing the freq of every character in count1
        for (int i = 0; i < s1.size(); i++){
            int charIndex = s1[i] - 'a';
            count1[charIndex]++;
        }
        
        //scanning for the first window
        int left = 0;
        int windowSize = s1.size();
        while (left < windowSize && left < s2.size()){
            int charIndex = s2[left] - 'a';
            count2[charIndex]++;
            left++;
        }
        if (checkEqual(count1, count2)){
            return true;
        }
        // scanning rest of the window
        while (left < s2.size()){
            // we got new window 
            int newCharIndex = s2[left] - 'a';
            count2[newCharIndex]++;
            int oldCharIndex = s2[left - windowSize] - 'a';
            // deleting element which is out of window
            count2[oldCharIndex]--;
            if (checkEqual(count1, count2)){
                return true;
            }
            left++;
        }
        return false;
    }
};
