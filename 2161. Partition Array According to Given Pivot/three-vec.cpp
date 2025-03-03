class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> Larr;
        vector<int> Rarr;
        vector<int> Marr;
        for(int num:nums){
            if(num<pivot) Larr.push_back(num);
            else if(num>pivot) Rarr.push_back(num);
            else Marr.push_back(num);
        }
        std::vector<int> result(Larr);
        result.insert(result.end(), Marr.begin(), Marr.end());
        result.insert(result.end(), Rarr.begin(), Rarr.end());
        return result;
    }
};
