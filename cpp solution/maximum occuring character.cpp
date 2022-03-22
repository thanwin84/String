class Solution
{
public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        vector<int> freq(26, 0);
        for (char ch : str) {
            int number = 0;
            if (ch >= 'a' && ch <= 'z') {
                number = ch - 'a';
            }
            else {
                number = ch - 'A';
            }
            freq[number] += 1;
        }
        int _max = 0;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > _max) {
              // this will make sure that we get the lowest value character
                ans = i;
                _max = freq[i];
            }
        }
        return ans + 'a';
    }

};
