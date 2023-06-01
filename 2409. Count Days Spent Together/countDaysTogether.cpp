#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA,leaveA,arriveB,leaveB;
        arriveA = countDays(arriveAlice.substr(0,2)) + stoi(arriveAlice.substr(3,2));
        leaveA  = countDays(leaveAlice.substr(0,2))  + stoi(leaveAlice.substr(3,2));
        arriveB = countDays(arriveBob.substr(0,2)) + stoi(arriveBob.substr(3,2));
        leaveB  = countDays(leaveBob.substr(0,2))  + stoi(leaveBob.substr(3,2));

        if(arriveA<=arriveB){
            if(leaveA>=leaveB) return leaveB-arriveB+1;
            else return ((1+leaveA)-arriveB)>0 ? ((1+leaveA)-arriveB):0;
        }
        else{
            if(leaveB>=leaveA) return leaveA-arriveA+1;
            else return ((1+leaveB)-arriveA)>0 ? ((1+leaveB)-arriveA):0;
        }
    }

    int countDays(string month){
        int m = stoi(month);
        int countDays = 0;
        for(int i=0;i<m-1;i++){
            countDays += months[i];
        }
        return countDays;
    }
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

int main(){

    Solution s;
    string arriveAlice = "02-01";
    string leaveAlice  = "02-28";
    string arriveBob  = "03-01";
    string leaveBob  = "03-31";
    cout<<s.countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob);
    return 0;
}