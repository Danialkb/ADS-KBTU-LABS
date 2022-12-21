#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int n, m;
void dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '0')return;
    a[i][j] = '0';
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}
int main() {
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++)a[i][j] = s[j];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j] == '1'){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
