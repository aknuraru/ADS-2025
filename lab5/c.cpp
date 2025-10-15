#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
public:
    vector<int> a;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    long long getMax() { return a[0]; }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;
        // Change: bubble up if GREATER than parent
        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        int j = left(i);
        // Change: find LARGEST child
        if (right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);
        // Change: swap if parent is SMALLER
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long extractMax() {
        long long root_value = getMax();
        if(a.empty()) return 0;
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }
    int getsize(){
        if(a.empty()) return 0;
        return a.size();
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    MaxHeap* heap=new MaxHeap();
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        heap->insert(x);
    }
    long long sum=0;
    for(int i=0;i<k;i++){
        long long c=heap->extractMax();
        sum+=c;
        c--;
        heap->insert(c);
    }
    cout<<sum;
    
    return 0;
}