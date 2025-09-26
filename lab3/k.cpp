#include <iostream>

using namespace std;

int getMin(int a, int b){
    if(a < b)
        return a;
    return b;
}

int binarySearch(int* p, int n, int k){
    int answer = n + 1;
    for(int i = 1; i <= n; i++){
        int left = 0, right = i - 1, position = -1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if(p[mid] <= p[i] - k){
                position = mid;
                left = mid + 1;
            }else
                right = mid - 1;
        }
        if(position != -1){
            answer = getMin(answer, i - position);
        }
    }
    return answer; 
}

int main(){
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    int* p = new int[n + 1];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + arr[i - 1];
    cout << binarySearch(p, n, k) ;
    return 0;
}