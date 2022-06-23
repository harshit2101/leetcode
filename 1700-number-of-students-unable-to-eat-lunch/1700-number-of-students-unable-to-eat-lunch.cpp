class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
          int eats0s = 0;
        
        for (int n : students) {
            if (n == 0) {
                eats0s++;
            }
        }
        int eats1s = students.size() - eats0s;
        int numSandwiches = sandwiches.size();
        
        for (int i=0; i<numSandwiches; ++i) {
            if (sandwiches[i] == 0) {
                if (eats0s == 0) {
                    // if we get a 0 sandwich and no one is left who
                    // eats 0s, then everyone left goes hungry because the top
                    // sandwich blocks them.
                    return (eats0s + eats1s);
                }
                else {
                    eats0s--;
                }
            }
            else {
                if (eats1s == 0) {
                    return (eats0s + eats1s);
                }
                else {
                    eats1s--;
                }
            }
        }
        
        return 0;
    }
};