class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string map[9][4] = {{"0"},{"a","b","c"},{"d","e","f"},{"g","h","i"},
        {"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
        for(char digit:digits){
            digit = digit-'0';
            vector<string>temp;
            for(string c:map[digit-1]){
                if(c=="") continue;
                if(ans.size()==0) temp.push_back(c);
                for(int i =0;i<ans.size();i++){
                    temp.push_back(ans[i]+c);
                }
            }
            ans = temp;
        }
        return ans;
    }
};
