class Solution {
public:  
int atMostK(vector<int> a,int n,int k)

    {   if(k==0) return 0;
        unordered_map<int,int> m;
        int ans=0,id=-1,l=0;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(m.count(a[i]))
                m[a[i]]++;
            else
            {
                if(m.size()==k)
                {
                    while(m.size()==k)
                    {
                        m[a[l]]--;
                        if(m[a[l]]==0)
                            m.erase(a[l]);
                        cnt+=(i-l);
                        l++;
                    }
                }
                m[a[i]]++;
            }
        }
            while(l<n)
             cnt+=(n-l),l++;
            return cnt;
    }
int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,nums.size(),k)-atMostK(nums,nums.size(),k-1);
    }
};