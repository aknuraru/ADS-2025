#include <iostream>
#include <string>
using namespace std;
struct listnode{
    string value;
    listnode* next;
    listnode(){
        this->value="che";
        this->next=nullptr;
    }
    listnode(string you_enter){
        this->value=you_enter;
        this->next=nullptr;
    }
};
struct linkedlist{
    int size;
    listnode* head;
    listnode* tail;
    linkedlist(){
        this->size=0;
        this->head=nullptr;
        this->tail=nullptr;
    }
    void addtail(string current_word){
        listnode* newnode=new listnode(current_word);
        this->size++;
        if(!this->tail){
            this->head=newnode;
            this->tail=newnode;
        }
        else{
            this->tail->next=newnode;
            this->tail=newnode;
        }
    }
    void solve(int k){
        this->tail->next=this->head;
        listnode* temporarily=nullptr;
        for(int i=0;i<k;i++){
            temporarily=this->head;
            this->head=this->head->next;
        }
        temporarily->next=nullptr;
        this->tail=temporarily;

    }
    void print(){
        listnode* current_node=head;
        while(current_node){
            cout<<current_node->value<<" ";
            current_node=current_node->next;
        }
    }

};
int main(){
    linkedlist* ll=new linkedlist();
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string current_word;
        cin>>current_word;
        ll->addtail(current_word);
    }
    ll->solve(k);
    ll->print();
    return 0;
}