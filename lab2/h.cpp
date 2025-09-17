#include <iostream>
using namespace std;
struct node{
    int value;
    node* next;
    node(){
        value=0;
        next=nullptr;
    }
    node(int val){
        value=val;
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
    void insert(int k,int p){
        node* nodes=new node(k);
        if(p==0){
            nodes->next=head;
            head=nodes;
        }
        else{
            node* curr=head;
            for(int i=0;i<p-1;i++){
                curr=curr->next;
            }
            nodes->next=curr->next;
            curr->next=nodes;
        }
        size++;
    }
    void remove(int p){
        if(!head) return;
        if(p==0){
            node* new_head=head->next;
            delete head;
            head=new_head;
        }
        else{
            node* curr=head;
            for(int i=0;i<p-1;i++){
                curr=curr->next;
            }
            node* to_delete=curr->next;
            curr->next=to_delete->next;
            delete to_delete;
            
        }
        size--;
    }
    void pr(){
        node* v=head;
        if(!head || size==0){
            cout<<-1<<endl;
        }
        else{
            while(v){
            cout<<v->value<<" ";
            v=v->next;
            }   
            cout<<endl;
        }
    }
    void replace(int p1,int p2){
        if(!head) return;
        node* temp;
        if(p1==0){
            temp=head;
            head=head->next;
        }
        else{
            node* curr=head;
            for(int i=0;i<p1-1;i++){
                curr=curr->next;
            }
            temp=curr->next;
            curr->next=curr->next->next;
        }
        size--;
        insert(temp->value,p2);
    }
    void reverse(){
        node* prev=nullptr;
        node* curr=head;
        node* nx=nullptr;
        while(curr){
            nx=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nx;
        }
        head=prev;
    }
    void left(int k){
        if(!head || k==0) return;
        k%=size;
        if(k==0) return;
        node* newhead=head;
        node* prev=nullptr;
        for(int i=0;i<k;i++){
            prev=newhead;
            newhead=newhead->next;
        }
        node* tail=head;
        while(tail->next){
            tail=tail->next;
        }
        tail->next=head;
        prev->next=nullptr;
        head=newhead;
    }
    void right(int k){
        if(!head || k==0) return;
        k%=size;
        if(k==0) return;
        left(size-k);
    }
};
int main(){
    linked* ll=new linked();
    while(true){
        int c;
        cin>>c;
        if(c==0){
            break;
        }
        else if(c==1){
            int k,p;
            cin>>k>>p;
            ll->insert(k,p);
        }
        else if(c==2){
            int p;
            cin>>p;
            ll->remove(p);
        }
        else if(c==3){
            ll->pr();
        }
        else if(c==4){
            int p1,p2;
            cin>>p1>>p2;
            ll->replace(p1,p2);
        }
        else if(c==5){
            ll->reverse();
        }
        else if(c==6){
            int k;
            cin>>k;
            ll->left(k);
        }
        else if(c==7){
            int k;
            cin>>k;
            ll->right(k);
        }
    }
    return 0;
}