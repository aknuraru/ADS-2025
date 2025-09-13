#include <iostream>
#include <queue>
using namespace std;

int main(){   
    queue<int> boris;
    queue<int> nursik;

    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        boris.push(a);
    }
    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        nursik.push(a);
    }

    int moves = 0;
    while(true){
        if(moves == 1000000){  
            cout << "blin nichya" << endl;
            return 0;
        }
        if(boris.size() == 0 || nursik.size() == 0){ 
            break;
        }

        int frontb = boris.front();
        int frontn = nursik.front();
        boris.pop();
        nursik.pop();

        if(frontb == 0 && frontn == 9){
            boris.push(frontb);
            boris.push(frontn);
        }
        else if(frontb == 9 && frontn == 0){
            nursik.push(frontb);
            nursik.push(frontn);
        }
        else if(frontb > frontn){
            boris.push(frontb);
            boris.push(frontn);
        }
        else{ 
            nursik.push(frontb);
            nursik.push(frontn);
        }
        moves++;
    }

    if(boris.size() == 0){
        cout << "Nursik " << moves << endl;
    }
    else{
        cout << "Boris " << moves << endl;
    }

    return 0;
}
