#include <iostream>

using namespace std;

int LAN(long long* arr, long long N, int len){
    int ctr=0;
    for(int i=0; i<len; i++){
        ctr+=arr[i]/N;
    }
    return ctr;
}

int main(){
    int K,N;

    cin>>K>>N;
    long long arr[K];

    long long max=0;
    for(int i=0; i<K; i++){
        cin>>arr[i];
        if(max<arr[i]) max=arr[i];
    }

    long long low=1;
    long long high=max;
    long long ans=0;

    while (low<=high){
        long long mid=(low+high)/2;
        
        if(LAN(arr,mid,K)>=N){
            if(ans<mid) low=mid;
            low=mid+1;
        }
        else high=mid-1;
    }

    cout<<ans;
    return 0;
}
