class CombinationIterator {
public:
    vector<int> a;
    vector<int> b;
    int stop;
    string s;
    int n;
    CombinationIterator(string characters, int combinationLength) {
        n = combinationLength;
        int m = characters.size();
        b.resize(n,0);
        stop = -1;
        s = characters;
        for(int i = 0; i<n;i++)
        {
            a.emplace_back(i);
        }
        for(int i=n-1, j=m-1; i>=0;i--,j--)
        {
            b[i]=j;
        }
        if(m==n)
            stop = 0;
    }
    
    string next() {
        string t;
        for(int i = 0; i<a.size();i++)
        {
            t+=s[a[i]];
        }
        int i= a.size()-1;
        bool bc=false;
        for( ; i> stop; i--)
        {
            if(a[i]<b[i])
            {
                a[i]++;
                bc=true;
                if(i==stop+1 && a[i]==b[i])
                {
                    stop = i;
                }
                break;
            }
        }
        if(!bc)
        {
            stop=n-1;
        }
        for(int j = i+1; j<a.size();j++)
        {
            a[j]= a[j-1]+1;
        }
        
        return t;
    }
    
    bool hasNext() {
       
        if(stop == n-1)
            return false;

        
        return true;
    }
};



/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */