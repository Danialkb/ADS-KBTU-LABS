#include <bits/stdc++.h>
using namespace std;
int a[7];

bool sdacha(int x){
    int cnt[7];
    for(int i = 0; i < 7; i++)cnt[i] = 0;
    while(a[6] > 0 && x - 100 >= 0){
        x -= 100;
        a[6]--;
        cnt[6]++;
    }
    while(a[5] > 0 && x - 50 >= 0){
        x -= 50;
        a[5]--;
        cnt[5]++;
    }
    while(a[4] > 0 && x - 20 >= 0){
        x -= 20;
        a[4]--;
        cnt[4]++;
    }
    while(a[3] > 0 && x - 10 >= 0){
        x -= 10;
        a[3]--;
        cnt[3]++;
    }
    while(a[2] > 0 && x - 5 >= 0){
        x -= 5;
        a[2]--;
        cnt[2]++;
    }
    while(a[1] > 0 && x - 2 >= 0){
        x -= 2;
        a[1]--;
        cnt[1]++;
    }
    while(a[0] > 0 && x - 1 >= 0){
        x -= 1;
        a[0]--;
        cnt[0]++;
    }
    if(x != 0){
        for(int i = 0; i < 7; i++){
            a[i] += cnt[i];
        }
    }
    // cout << x << endl;
    return x == 0;
    
}

int main() {
    freopen("output.txt", "w", stdout);
    int n;
    int sum = 0;
    for(int i = 0; i < 7; i++){
        cin >> a[i];

    }
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << (sdacha(x) ? "Transaction accepted!\n" : "Transaction stopped!\n");
    }



    return 0;
}