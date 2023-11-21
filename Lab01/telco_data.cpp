//CPP 
#include <bits/stdc++.h> 
using namespace std;

bool check_phone_number(string s){
    if(s.length() != 10) return false;
    for(int i = 0; i < s.length(); i++){
        if(!(s[i] >= '0' && s[i] <= '9')) return false;
    }
    return true;
}

int countTime(string ftime, string ttime){
    int startTime = 3600*((ftime[0] - '0')*10 + ftime[1] - '0') 
    + 60*((ftime[3] - '0')*10 + ftime[4] - '0') 
    + ((ftime[6] - '0')*10 + ftime[7] - '0');

    int endTime = 3600*((ttime[0] - '0')*10 + ttime[1] - '0') 
    + 60*((ttime[3] - '0')*10 + ttime[4] - '0') 
    + ((ttime[6] - '0')*10 + ttime[7] - '0');
    
    return endTime - startTime;
}

map <string, int> numberCalls, timeCall;

int main() {   
    freopen("telco_data.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalcalls = 0;
    int incorrectPhone = 0;

    do{
        cin >> type;
        if(type == "#") continue;
        ++totalcalls;
        string fnum, tnum, date, ftime, ttime;
        cin >> fnum >> tnum >> date >> ftime >> ttime;
        if(!check_phone_number(fnum) || !check_phone_number(tnum)) ++incorrectPhone;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, ttime);
      
    }while(type != "#");

    do{
        cin >> type;
        if(type == "#") continue;
         if(type == "?check_phone_number"){
            incorrectPhone == 0 ? cout << 1 << endl : cout << 0 << endl;
        }else if(type == "?number_calls_from"){
            string phone; cin >> phone;
            cout << numberCalls[phone] << endl;
        }else if (type == "?number_total_calls"){
            cout << totalcalls << endl;
        }else if(type == "?count_time_calls_from"){
            string phone; cin >> phone;
            cout << timeCall[phone] << endl;
        }
      
    }while(type != "#");
    return 0;
}
