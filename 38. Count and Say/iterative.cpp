class Solution {
public:
    string countAndSay(int n) {
       string output = "1";
       for(int i =1;i<n;i++){
        string next = "";
        int cnt = 0;
        char current_c;
        int len_o = output.size();
        for(int j = 0;j<len_o;j++){
            if(j==0) current_c = output[j];
            if(current_c==output[j]){ 
                cnt += 1;
            }
            else{
                next += cnt + '0';
                next += current_c;
                cnt = 1;
                current_c = output[j];
            }
            if(j==len_o-1){
                next += cnt+'0';
                next += output[j];
            }
        }
        cout<<output<<endl;
        output = next;
       }
       return output; 
    }
};
