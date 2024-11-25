#include<iostream>
using namespace std;

int knapsack(int n,int weight[],int value[], int capacity){
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=capacity;++j){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(weight[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],value[i-1]+dp[i-1][j-weight[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}
int main(){
    int n1 = 4;
    int weights1[] = {1, 3, 4, 5};
    int values1[] = {1, 4, 5, 7};
    int capacity1 = 7;

    int n2 = 3;
    int weights2[] = {2, 3, 4};
    int values2[] = {3, 4, 5};
    int capacity2 = 5;
    cout<<knapsack(n1,weights1,values1,capacity1)<<endl;
        cout<<knapsack(n2,weights2,values2,capacity2)<<endl;

}