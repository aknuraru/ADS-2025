#include <iostream>
#include <string>
using namespace std;
struct node{
    string value;
    node* next;
    node* prev;
    node(){
        value="ch";
        next=nullptr;
        prev=nullptr;
    }
    node(string val){
        value=val;
        next=nullptr;
        prev=nullptr;
    }
};
struct doublelinked{
    int size;
    node* head;
    node* tail;
    doublelinked(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }
    void add_front(string str){
        node* nodes=new node(str);
        if(size==0){
            head=nodes;
            tail=nodes;
        }
        else{
            nodes->next=head;
            head->prev=nodes;
            head=nodes;
        }
        size++;
    }
    string add_back(string str){
        node* nodes=new node(str);
        if(size==0){
            head=nodes;
            tail=nodes;
        }
        else{
            tail->next=nodes;
            nodes->prev=tail;
            tail=nodes;
        }
        size++;
        return "ok";
    }
    string erase_front(){
        if(size==0){
            return "error";
        }
        node* curr=head;
        string val=curr->value;
        head=head->next;
        if(head){
            head->prev=nullptr;
        }
        else{
            tail=nullptr;
        }
        delete curr;
        size--;
        return val;
    }
    string erase_back(){
        if(size==0){
            return "error";
        }
        node* curr=tail;
        string val=curr->value;
        tail=tail->prev;
        if(tail){
            tail->next=nullptr;
        }
        else{
            head=nullptr;
        }
        delete curr;
        size--;
        return val;
    }
    string front(){
        if(size==0){
            return "error";
        }
        else{
            return head->value;
        }
    }
    string back(){
        if(size==0){
            return "error";
        }
        else{
            return tail->value;
        }
    }
    string clear(){
        while(head){
            node*curr=head;
            head=head->next;
            delete curr;
        }
        head=nullptr;
        tail=nullptr;
        size=0;
        return "ok";
    }
};
int main(){
    doublelinked* ll=new doublelinked();
    while(true){
        string str;
        cin>>str;
        if(str=="exit"){
            cout<<"goodbye"<<endl;
            break;
        }
        else if(str=="add_front"){
            string book;
            cin>>book;
            ll->add_front(book);
            cout<<"ok"<<endl;
        }
        else if(str=="add_back"){
            string book;
            cin>>book;
            cout<<ll->add_back(book)<<endl;
        }
        else if(str=="erase_front"){
            cout<<ll->erase_front()<<endl;
        }
        else if(str=="erase_back"){
            cout<<ll->erase_back()<<endl;
        }
        else if(str=="front"){
            cout<<ll->front()<<endl;
        }
        else if(str=="back"){
            cout<<ll->back()<<endl;
        }
        else if(str=="clear"){
            cout<<ll->clear()<<endl;
        }
    }
    return 0;
}