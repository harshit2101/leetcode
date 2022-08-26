class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;
        char smChar = letters[0];
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (letters[mid] > target) {
                end = mid - 1;
                smChar = letters[mid];
            } else {
                start = mid + 1;
            }
        }
        
        return smChar;        

    }
};