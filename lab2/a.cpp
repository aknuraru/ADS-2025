#include <iostream>
#include <cmath>
using namespace std;
struct listnode{
    int value;
    listnode* next;
    listnode(){
        this->value=0;
        this->next=nullptr;
    }
    listnode(int the_num_you_entered){
        this->value=the_num_you_entered;
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
    void Newtail(int value_of_newnode){
        listnode* newnode=new listnode(value_of_newnode);
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
    int doit(int k){
        listnode* current_node=this->head;
        int nearest=abs(k-current_node->value);
        int index=0;
        int counts=1;
        current_node=current_node->next;
        while(current_node){
            if(abs(k-current_node->value)<nearest){
                nearest=abs(k-current_node->value);
                index=counts;
            }
            current_node=current_node->next;
            counts++;
        }
        return index;
    }
    

};
int main(){
    int n,k;
    cin>>n;
    linkedlist* ll=new linkedlist();
    while(n--){
        int x;
        cin>>x;
        ll->Newtail(x);
    }
    cin>>k;
    int result=ll->doit(k);
    cout<<result<<endl;
    return 0;
}
