#include <iostream>
#include <string>
using namespace std;
struct node{
    char value;
    node* next;
    bool istodelete;
    node(char ch){
        value=ch;
        next=nullptr;
        istodelete=false;
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
    void check(char ch){
        node* curr=head;
        while(curr){
            if(curr->value==ch){
                curr->istodelete=true;
                return;
                if(curr==head){
                    head=curr->next;
                    delete curr;
                    return;
                }
            }
            curr=curr->next;
        }
        node* nodes=new node(ch);
        if(!head){
            head=nodes;
            tail=nodes;
        }
        else{
            tail->next=nodes;
            tail=nodes;
        }
    }
    string getfirstunique(){
        node* curr=head;
        while(curr){
            if(!curr->istodelete){
                return string(1,curr->value);
            }
            curr=curr->next;
        }
        return "-1";
    }
    void clear(){
        while(head){
            node* curr=head;
            head=head->next;
            delete curr;
        }
        tail=nullptr;
    }

};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        linked* ll=new linked();
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            char ch;
            cin>>ch;
            ll->check(ch);
            cout<<ll->getfirstunique()<<" ";
        }
        cout<<endl;
        ll->clear();
    }
    return 0;
}