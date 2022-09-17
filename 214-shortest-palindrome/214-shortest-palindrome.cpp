class Solution {
public:
    string shortestPalindrome(string s) {
		string t=s;
		reverse(t.begin(),t.end());
		string str=s+"#"+t;
		int n=str.length();
		int i=1,j=0;
		vector<int> kmp(n);
		while(i<n) {
			if(j<n&&str[i]==str[j]) {
				kmp[i++]=++j;
			}
			else {
				if(j!=0) j=kmp[j-1];
				else kmp[i++]=j;
			}
		}
		string l=s.substr(kmp[n-1]);
		reverse(l.begin(),l.end());
		return l+s;
	}
};