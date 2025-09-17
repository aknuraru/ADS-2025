#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int value;
    int mode;
    node* next;
    node(){
        value=0;
        mode=0;
        next=nullptr;
    }
    node(int value){
        this->value=value;
        this->next=nullptr;
        this->mode=1;
    }
};
struct linked{
    int size;
    int max;
    node* head;
    node* tail;
    linked(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }
    void jananode(int k){
        if(!head){
            node* n1=new node(k);
            head=n1;
            tail=n1;
            size++;
        }
        else{
            node* curr=head;
            while(curr){
                if(curr->value==k){
                    curr->mode++;
                    break;
                }
                if(!curr->next){
                    node* n1=new node(k);
                    tail->next=n1;
                    tail=n1;
                    size++;
                    break;
                }
                curr=curr->next;
            }
        }
    }
    int getmax(){
        int max=head->mode;
        node* curr=head;
        while(curr){
            if(curr->mode>max){
                max=curr->mode;
            }
            curr=curr->next;
        }
        return max;
    }
    void answ(){
        node* curr=head;
        max=getmax();
        vector<int>res;
        while(curr){
            if(curr->mode==max){
                res.push_back(curr->value);
            }
            curr=curr->next;
        }
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }

    }

};
int main(){
    int n;
    cin>>n;
    linked* h=new linked();
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        h->jananode(x);
    }
    h->answ();
    return 0;
}