class Solution {
public:
    unordered_map<string,bool> mp;          //Create Map Globally
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())          //Checking length of both string
            return false;
        if(s1.size()==0 && s2.size()==0)    //If both strings are empty
            return true;
        if(s1.compare(s2)==0)               //If both strings are same
            return true;
        if(s1.size()<=1)                    //Check size of String s1 is less tha 1 OR not
            return false;
        
        
        string key=s1;                      //Generating Key for Map which should be unique
        key.push_back(' ');
        key.append(s2);
        if(mp.find(key) != mp.end())        //Storing value in map if found 
            return mp[key];
        /*Till now if we didn't find our value then we will calculate particularly */
        int n=s1.size();
        bool flag=false;
        for(int i=1;i<n;i++) {
            if((isScramble(s1.substr(0,i),s2.substr(n-i,i))==true
              && isScramble(s1.substr(i,n-i),s2.substr(0,n-i))==true)
                                      || 
               (isScramble(s1.substr(0,i),s2.substr(0,i))==true
                && isScramble(s1.substr(i,n-i),s2.substr(i,n-i))==true)) {
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
};