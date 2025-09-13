#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    queue<char>q;
    int countK=0,pointK=0;
    int countS=0,pointS=0;
    int banK=0,banS=0;
    for(int i=0;i<s.size();i++){
        q.push(s[i]);
        if(s[i]=='K'){
            countK++;
        }
        else{
            countS++;
        }
    }
    while(true){
        if (q.front()=='K'){
            if(banK>0){
                q.pop();
                banK--;
                countK--;
            }
            else{
                q.push('K');
                q.pop();
                banS++;
                pointK++;
            }
        }
        else if (q.front()=='S'){
            if(banS>0){
                q.pop();
                banS--;
                countS--;
            }
            else{
                q.push('S');
                q.pop();
                banK++;
                pointS++;
            }
        }
        if(countK==0 || countS==0){
            if(pointK>pointS){
                cout<<"KATSURAGI"<<endl;
                return 0;
            }
            else{
                cout<<"SAKAYANAGI"<<endl;
                return 0;
            }
        }
    }
    return 0;

}