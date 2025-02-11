class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack;
        int p = part.size();
        char end = part.back();
        
        for(char current:s){
            stack.push_back(current);
            if(current == end && stack.size()>=p){
                if(stack.substr(stack.size()-p)==part){
                    stack.erase(stack.size()-p);
                }
            }
        }
        return stack;
    }
};
