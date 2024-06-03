//https://atcoder.jp/contests/abc355/tasks/abc355_c

#include <iostream>
#include <vector>
#define BUF 2048
using namespace std;

int main(void){    

    int n,t,a,x,y;
    int out = -1;
    int row[BUF] = {0};
    int col[BUF] = {0};
    int diag_right = 0;//右上から左下
    int diag_left = 0;//右下から左上

    cin >> n >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a;
        if(out != -1){
            continue;
        }

        if(a%n != 0){
            x = a/n;
            y = (a%n) - 1;
        }else{
            x = (a/n) - 1;
            y = n-1;
        }

        //cout << "x = " << x << " | y = " << y << endl; 

        row[x]++;
        if(row[x] == n){
            out = i + 1;
        }

        col[y]++;
        if(col[y] == n){
            out = i + 1;
        }

        if(x == y){
            diag_right++;
            if (diag_right == n)
            {
                out = i + 1;
            } 
        }

        if(x + y == n-1){
            diag_left++;
            if(diag_left == n){
                out = i + 1;
            }
        }
    }

    cout << out << endl;
    

    return 0;

}
