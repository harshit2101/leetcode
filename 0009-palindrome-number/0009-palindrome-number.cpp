class Solution {
public:
    bool isPalindrome(int x) {
        
        long long rem, rev=0;
        
        if(x<0) return 0;
        
        
        long long n=x;
        while(n>0){
            
            rem=n%10;
            rev=rev*10+rem;
            n/=10;
        }
        
        if(rev==x) return true;
        return false;
    }
};