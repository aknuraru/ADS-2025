#include <iostream>
#include <climits>
using namespace std;
struct node{
    int value;
    node* next;
    node(int k){
        value=k;
        next=nullptr;
    }
};
struct linked{
    int size;
    node* head;
    node* tail;
    linked(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }
    void push(int k){
        node* newa=new node(k);
        if(!tail){
            head=newa;
            tail=newa;
        }
        else{
            tail->next=newa;
            tail=newa;
        }
        size++;
    }
    int maxofarr(){
        node* curr=head;
        int max_sum_arr=0;
        int maxs=INT_MIN;
        while(curr){
            max_sum_arr=max(curr->value,max_sum_arr+curr->value);
            maxs=max(maxs,max_sum_arr);
            curr=curr->next;
        }
        return maxs;
    }
};
int main(){
    int n;
    cin>>n;
    linked* ll=new linked();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll->push(x);
    }
    cout<<ll->maxofarr();
    return 0;
}