#include<iostream>
#include<string>
using namespace std;
struct student{
    string name;
    int score;
};

void swap(student& a,student& b){
    student temp = a;
    a = b;
    b = temp;
}
int partition(student arr[],int low, int high){
    int pivot = arr[high].score;
    int i = low-1;
    for(int j = low;j<high;++j){
        if(arr[j].score<=pivot){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(student arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main(){
    student s[] = {
        {"Alice", 50},
        {"Bob", 80},
        {"Charlie", 100},
        {"David", 90}
    };
    int n = sizeof(s)/sizeof(s[0]);
    quicksort(s,0,n-1);
    for(int i=0;i<n;++i){
        cout<<s[i].name<<":"<<s[i].score<<endl;
    }
}