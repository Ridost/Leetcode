class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector <int> answer(len);
        vector <int> stack;
        stack.push_back(0);
        for(int i = 1;i<len;i++){
            while(temperatures[stack.back()]<temperatures[i]){
                answer[stack.back()] = i - stack.back();
                stack.pop_back();
                if(stack.empty()) break;
            }
            stack.push_back(i);
        }
        return answer;
    }
};
