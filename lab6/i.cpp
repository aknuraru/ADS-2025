#include <iostream>

using namespace std;

const int max_size = 500000;

struct MinHeap
{
    int size;
    char heap[max_size];

    MinHeap(){
        size = 0;
    }

    int parent(int i){
        return (i - 1) / 2;
    }

    int left(int i){
        return i * 2 + 1;
    }

    int right(int i){
        return i * 2 + 2;
    }

    void my_swap(char& a, char& b){
        char t = a;
        a = b;
        b = t;
    }

    void insert(char value){
        int i = size;
        heap[size++] = value;

        while(i > 0 && heap[i] < heap[parent(i)]){ // 'a' > 'b' = false
            my_swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if(l < size && heap[l] < heap[smallest])
            smallest = l;
        if(r < size && heap[r] < heap[smallest])
            smallest = r;
        
        if(smallest != i){
            my_swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    char extractMin(){
        if ( size == 0) return '0';
        char root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return root;
    }

    bool isEmpty(){
        if(size == 0)
            return true;
        return false;
    }
};


int main(){
    string text;
    cin >> text;
    MinHeap heap;
    for(char ch : text){
        heap.insert(ch);
    }

    while (!heap.isEmpty())
    {
        cout << heap.extractMin();
    }
    

    return 0;
}