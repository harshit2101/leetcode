class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        
        int i=0,j=tokens.size()-1;
        int ans=0,score=0;
        
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                ans=max(ans,score);
                power-=tokens[i];
                i++;
            }
            else if(score>0){
                score--;
                power+=tokens[j];
                j--;
            }
            else break;
        }
        
        return ans;
    }
};