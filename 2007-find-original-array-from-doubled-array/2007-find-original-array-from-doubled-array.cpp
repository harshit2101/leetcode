class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
	    if(n%2!=0) return {};

	unordered_map<int,int> mp;
	for(int i=0; i<n; i++) mp[changed[i]]++;

	vector<int> res;
	sort(changed.begin(), changed.end());
	
	for(int i=0; i<n; i++)
	{
		
		if(mp[changed[i]]==0) continue;

		if(mp[changed[i]*2]==0) 
			return {};

		mp[changed[i]*2]--;
		mp[changed[i]]--; 
		res.push_back(changed[i]);
	}
	return res;
    }
};