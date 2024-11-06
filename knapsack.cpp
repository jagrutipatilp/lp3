#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int>p1, pair<int,int>p2){
    double v1 = p1.first/p1.second;
    double v2 = p2.first/p2.second;

    return v1>v2;
}

int main(){
    int n=0;
    cout<<"Enter the number of items"<<endl;
    cin>>n;

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){
        cout<<"Enter the profit and weight of item "<<i+1<<endl;
        cin>>a[i].first>>a[i].second;
    }

    int weight=0;
    cout<<"Enter the capacity of knapsack"<<endl;
    cin>>weight;

    sort(a.begin(),a.end(),compare);

    double ans=0;
    for(int i=0;i<n;i++){
        if(weight>=a[i].second){
            ans+=a[i].first;
            weight -= a[i].second;
            continue;
        }
        double ratio = a[i].first/a[i].second;
        ans += ratio*weight;
        weight = 0;
        break;
    }
    cout<<"The maximum profit is"<<endl;
    cout<<ans;
}