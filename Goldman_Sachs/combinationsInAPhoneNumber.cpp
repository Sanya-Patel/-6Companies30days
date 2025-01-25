class Solution {
public:
    vector<string>res; 
    void solve(int idx,string digits,string &temp, unordered_map<char,string>mp)
    {
       if(idx>=digits.length())
       {
        res.push_back(temp);
        return;
       }
           
        char ch = digits[idx]; 
        string s = mp[ch];  

        for( int i=0;i<s.length();i++)
        {
            temp.push_back(s[i]);
            solve(idx+1,digits,temp,mp); // if(digit=234) idx=0 ,will take the next idx 2->3->4 (adg,adh,adi) and then pop back as the idx = 3 and length of digit is 3
            temp.pop_back();
        }

    }
   

    vector<string> letterCombinations(string digits) {
      if(digits.length()==0)
      {
        return {};
      }
        string temp="";
        unordered_map<char,string>mp; //mapped the char with the string 
         mp['2']="abc";
         mp['3']="def";
         mp['4']="ghi";
         mp['5']="jkl";
         mp['6']="mno";
         mp['7']="pqrs";
         mp['8']="tuv";
         mp['9']="wxyz";
        solve(0,digits,temp,mp);
        return res;
    }
};