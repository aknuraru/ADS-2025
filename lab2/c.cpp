#include <iostream>
using namespace std;
struct node{
    int value;
    node* next;
    node(){
        this->value=0;
        this->next=nullptr;
    }
    node(int val){
        this->value=val;
        this->next=nullptr;
    }
};
struct linked{
    int size;
    node* head;
    node* tail;
    linked(){
        this->size=0;
        this->head=nullptr;
        this->tail=nullptr;
    }
    void addtail(int values){
        node* n1=new node(values);
        this->size++;
        if(!this->tail){
            this->tail=n1;
            this->head=n1;
        }
        else{
            this->tail->next=n1;
            this->tail=n1;
        }
    }
    void solve(){
        node* current=head;
        int count=0;
        while(current){
            if(count%2==0){
                cout<<current->value<<" ";
            }
            count++;
            current=current->next;
        }
    }
};
int main(){
    int n;
    cin>>n;
    linked* ll=new linked();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll->addtail(x);
    }
    ll->solve();
    return 0;
}