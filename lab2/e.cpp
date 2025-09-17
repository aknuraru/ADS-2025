#include <iostream>
using namespace std;
struct node{
    string value;
    node* next;
    node(){
        value="em";
        next=nullptr;
    }
    node(string soz){
        value=soz;
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
    void push_back(string ss){
        node* n1=new node(ss);
        size++;
        if(!tail){
            head=n1;
            tail=n1;
        }
        else{
            tail->next=n1;
            tail=n1;
        }
    }
    void push_front(string ss){
        node* n1=new node(ss);
        if(!head){
            head=n1;
            tail=n1;
            size++;
        }
        else{
            if(head->value!=n1->value){
                n1->next=head;
                head=n1;
                size++;
            }
        }
    }

    void printd(){
        node* curr=head;
        cout<<"All in all: "<<size<<endl;
        cout<<"Students:"<<endl;
        while(curr){
            cout<<curr->value<<endl;
            curr=curr->next;
        }
    }
};
int main(){
    int n;
    cin>>n;
    linked* ll=new linked();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ll->push_front(s);
    }
    ll->printd();
    return 0;
}