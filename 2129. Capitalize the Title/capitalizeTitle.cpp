#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> titles = split(title);
        string ans = "";
        for (int i=0;i<titles.size();i++){
            for(int j=0;j<titles[i].size();j++){
                if(titles[i].size()>=3 && j==0) titles[i][j] = toupper(titles[i][j]);
                else titles[i][j] = tolower(titles[i][j]);
            }
            ans += " "+titles[i];
        }
        return ans.substr(1);
    }
    vector<string> split(string s){
        vector<string> ans;
        while(s.find(" ")!=-1){
            ans.push_back(s.substr(0,s.find(" ")));
            s = s.substr(s.find(" ")+1);
        }
        ans.push_back(s);
        return ans;
    }
};