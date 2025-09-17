#include <iostream>
using namespace std;
struct node{
    int value;
    node* next;
    node(){
        value=0;
        next=nullptr;
    }
    node(int v){
        value=v;
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
    void pushback(int val){
        node* nodes=new node(val);
        size++;
        if(!tail){
            head=nodes;
            tail=nodes;
        }
        else{
            tail->next=nodes;
            tail=nodes;
        }
    }
    void pushfront(int val){
        node* nodes=new node(val);
        size++;
        if(!head){
            head=nodes;
            tail=nodes;
        }
        else{
            nodes->next=head;
            head=nodes;
        }
    }
    void pushmid(int val,int index){
        node* nodess=new node(val);
        node* curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
        }
        nodess->next=curr->next;
        curr->next=nodess;
        size++;
    }
    void inst(int val,int index){
        node* no=new node(val);
        if(index==0){
            pushfront(val);
        }
        else{
            pushmid(val,index);
        }
    }
    void pr(){
        node* curr=head;
        while(curr){
            cout<<curr->value<<" ";
            curr=curr->next;
        }
    }
};
int main(){
    int n,value,index;
    cin>>n;
    linked* ll=new linked();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll->pushback(x);
    }
    cin>>value>>index;
    ll->inst(value,index);
    ll->pr();
    return 0;
}