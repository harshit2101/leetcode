class TrieNode
{
	public:
		bool isWord;
        int countPrefix;
		TrieNode *child[26];
	
		TrieNode()
		{
			isWord=0;
            countPrefix=0;
			for(TrieNode* &i:child)
			{
				i=NULL;
			}
		}
};

class Trie
{
	public: 
		Trie()
		{
			head=new TrieNode();
		}
	
		TrieNode *head=NULL;
	
		void insert(string word)
		{
			TrieNode *temp=head;
			
			for(char &i:word)
			{
				if(temp->child[i-'a']==NULL)
				{
					temp->child[i-'a']=new TrieNode();
				}
				temp=temp->child[i-'a'];
                temp->countPrefix++;
			}
			temp->isWord=1;
		}
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int n=strs.size();
        
        Trie trie;
	
        for(string &i:strs)
        {
            trie.insert(i);
        }

        string ans;
        
        string res=strs.back();
        
        TrieNode* temp=trie.head;
        
        for(char &i:res)
        {          
            if(temp->child[i-'a'] && temp->child[i-'a']->countPrefix==n)
            {
                ans+=i;
            }
            else
            {
                break;   
            }
            
            temp=temp->child[i-'a'] ;
        }
        
        return ans;
    }
};