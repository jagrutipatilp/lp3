#include<iostream>
using namespace std;

void fibonacci(int num){
    int a = 0;
    int b = 1;
    if(num==0){
        cout<<a;
        return;
    }
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<num-1;i++){
        int c = a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
}

int rec_fibonacci(int num){
    if(num==1){
        return 1;
    }else if(num==0){
        return 0;
    }
    return rec_fibonacci(num-1) + rec_fibonacci(num-2); 
    
}

int main(){
    fibonacci(0);
    cout<<endl;
    int num = rec_fibonacci(0);
    cout<<num;
}