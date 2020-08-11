class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i,j,n=citations.size();
        sort(citations.begin(),citations.end());
        if(n==0)
            return 0;
        int ans=1;
        for(i=0;i<n;i++){
            if(n-i<=citations[i])
                return n-i;
        }
        return 0;
    }
};