#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int pos=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            int mi=a[i];
            int pos2=i;
            for(int j=i+1;j<n;j++){
                if(mi>a[j]){
                    mi=a[j];
                    pos2=j;
                }
            }
            for(int j=pos2-1;j>=i;j--){
                swap(a[j],a[j+1]);
            }
            if(pos2!=i)
                i=pos2-1;
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
  return  0;
}