class Solution {
public:
    bool is_vovel(char ch){
      ch = tolower(ch);
      if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u')
        return true;
     return false;
    }
    
    string toGoatLatin(string str) {
      stringstream ss(str);
      string temp, succ = "maa", ans = "";
      while(!ss.eof()){
        ss >> temp;
        if(!is_vovel(temp[0])){
         char tp = temp[0];
         temp.erase(temp.begin());
         temp.push_back(tp);
      }
      temp += succ;
      succ.push_back('a');
      ans += (temp + ' ');
     }     
     return ans.substr(0,ans.size() - 1);
   }
};