#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double getGPA(const string &mark) {
    if (mark == "A+") return 4.0;
    if (mark == "A")  return 3.75;
    if (mark == "B+") return 3.5;
    if (mark == "B")  return 3.0;
    if (mark == "C+") return 2.5;
    if (mark == "C")  return 2.0;
    if (mark == "D+") return 1.5;
    if (mark == "D")  return 1.0;
    return 0.0;
}

struct Student {
    string surname;
    string name;
    double gpa;
    void print() const {
        cout << fixed << setprecision(3) << surname << " " << name << " " << gpa << "\n";
    }
};

const double EPS = 1e-9;

bool lessThan(const Student &a, const Student &b) {
    if (fabs(a.gpa - b.gpa) > EPS) return a.gpa < b.gpa; // ascending by gpa
    if (a.surname != b.surname) return a.surname < b.surname;
    return a.name < b.name;
}

void merge(Student arr[], int left, int mid, int right){
    Student result[right - left + 1];
    int i = left;
    int j  = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if(lessThan(arr[i], arr[j])){
            result[k] = arr[i];
            k++;
            i++;
        }else{
            result[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        result[k] = arr[i];
        k++;
        i++;
    }
    
    while (j <= right)
    {
        result[k] = arr[j];
        k++;
        j++;
    }

    for(int p = 0; p < k; p++){
        arr[left + p] = result[p];
    }
}

void mergeSort(Student arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand((unsigned) time(nullptr));

    int n;
    if (!(cin >> n)) return 0;
    Student *students = new Student[n];
    for (int i = 0; i < n; ++i) {
        string surname, name;
        cin >> surname >> name;
        int subjects;
        cin >> subjects;
        long long totalCredits = 0;
        double sum = 0.0;
        for (int k = 0; k < subjects; ++k) {
            string mark;
            int credits;
            cin >> mark >> credits;
            sum += getGPA(mark) * credits;
            totalCredits += credits;
        }
        students[i].surname = surname;
        students[i].name = name;
        students[i].gpa = sum / (double)totalCredits; // keep full precision for sorting
    }

    mergeSort(students, 0, n - 1);

    for (int i = 0; i < n; ++i) students[i].print();

    delete[] students;
    return 0;
}