#include<iostream>
#include<algorithm>
using namespace std;
struct item{
    double value,weight;
};
bool compare(item a,item b){
    return(a.value/a.weight)>(b.value/b.weight);
}
double fractionalknapsack(item i[],int n,double capacity){
    sort(i,i+n,compare);
    double total = 0;
    for(int j = 0;j<n;j++){
        if(capacity>=i[j].weight){
            total+=i[j].value;
            capacity-=i[j].weight;
        }else{
            total+=i[j].value*(capacity/i[j].weight);
            break;
        }
    }
            return total;
}
int main(){
    int t;
    cin>>t;

    while(t){
        int n;
    double capacity;
 cin>>n;
        item i[n];
        t--;
        for(int k = 0;k<n;k++){
            cin>>i[k].value>>i[k].weight;
        }
        cin>>capacity;
        double max = fractionalknapsack(i,n,capacity);
        cout<<max<<endl;
    }
}