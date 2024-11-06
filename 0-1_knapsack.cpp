#include<iostream>
using namespace std;

int main(){
    int n=0;
    cout<<"Enter the number of items"<<endl;
    cin>>n;

    int capacity=0;
    cout<<"Enter the capacity of knapsack"<<endl;
    cin>>capacity;

    int price[n+1]={0};
    int weight[capacity+1]={0};
    int dp[n+1][capacity+1];

    for(int i=1;i<n+1;i++){
        cout<<"Enter the profit and weight of item "<<i<<endl;
        cin>>price[i]>>weight[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(weight[i]<=j){
                dp[i][j] = max(dp[i-1][j], price[i]+dp[i-1][j-weight[i]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=capacity;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"The maximum profit is: "<<dp[n][capacity];
}