class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
       int sumA = 0;
    int sumB = 0;
    
    for (auto e : A)
        sumA += e;
    
    for (auto e : B)
        sumB += e;
    
    int delta = (sumA - sumB) / 2;
    
    unordered_set<int> searchA;
    for (auto x : A)
    {

        searchA.insert(x);
    }
    
    
    //cout << endl;
    for (auto y : B)    
    {
    
        if (searchA.find(delta + y) !=searchA.end())
        {
            return {delta + y, y};
        }
    }
    
    return vector<int>();
}
    
};