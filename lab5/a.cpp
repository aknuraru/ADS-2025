#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    public:
    vector<long long> a;
    int getsize(){
        return a.size();
    }

    // Get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Get left child index
    int left(int i) {
        return 2 * i + 1;
    }

    // Get right child index
    int right(int i) {
        return 2 * i + 2;
    }

    // Get minimum element (root) - O(1)
    long long getMin() {
        return a[0];
    }

    // Insert element - O(log n)
    void insert(long long k) {
        // Add element at the end
        a.push_back(k);
        int ind = a.size() - 1;

        // Heapify up: bubble up the element
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    // Heapify down - O(log n)
    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;

        // Find smallest among node and its children
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

        // If parent is greater than smallest child, swap and continue
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    // Extract minimum element - O(log n)
    long long extractMin() {
        long long root_value = getMin();

        // Replace root with last element
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        // Heapify down from root
        if (a.size() > 0)
            heapify(0);

        return root_value;
    }
};

int main() {
    int n;
    cin >> n;
    MinHeap *heap = new MinHeap();

    // Insert n elements
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap->insert(x);
    }

    if(heap->getsize()==1){
        cout<<heap->extractMin()<<" ";
        return 0;
    }
    long long sum=0;
    while(heap->getsize()>1){
        long a=heap->extractMin();
        long b=heap->extractMin();
        long c=a+b;
        heap->insert(c);
        sum+=c;
    }
    cout<<sum<<" ";

    return 0;
}