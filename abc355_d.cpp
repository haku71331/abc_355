//https://atcoder.jp/contests/abc355/tasks/abc355_d
//解説を参照しました。
//https://atcoder.jp/contests/abc355/editorial/10077

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long llint;

int main(void){
    
    llint n,ans;
    llint c = 0;
    llint l,r;
    vector<llint> vec_L,vec_R;

    cin >> n;

    for (llint i = 0; i < n; i++)
    {
        cin >> l >> r;
        vec_L.push_back(l);
        vec_R.push_back(r);
    }

    sort(vec_L.begin(),vec_L.end());
    sort(vec_R.begin(),vec_R.end());

    /*
    cout << "vec_L = {";
    for (int i = 0; i < n; i++)
    {
        cout << vec_L[i] << ",";
    }
    cout << "}" << endl;

    cout << "vec_R = {";
    for (int i = 0; i < n; i++)
    {
        cout << vec_R[i] << ",";
    }
    cout << "}" << endl;
    */
    

    ans = n * (n-1)/2;
    for (llint i = 0; i < n; i++)
    {
        while (vec_R[c] < vec_L[i])
        {
            //cout << "increment c! when c = " << c << ", vec_R[c] = "<< vec_R[c] << ", vec_L[i] = " << vec_L[i] << ", i = " << i << endl;
            c++;
        }
        ans = ans - c; 
        //cout << "ans = " << ans << ", when c = "<< c << endl;   
    }

    cout << ans << endl;

    return 0;
}

/*
共通区間になる条件
すべての区間の組について共通部分を持つかどうか調べるとO(N^2) 時間かかり，実行時間制限に間に合いません．
適切なアルゴリズムを用いて高速化する必要があります．

ここで，共通部分を持つ区間の組を数える代わりに，共通部分を持たない区間の組の個数 
x を求めてN(N−1)/2 から引くことで答えを求めることにします（これは，「余事象を考える」という典型的な考え方です）．

区間i の左にあって区間i と共通部分を持たない区間はr_j<l_iを満たす区間j です．よって，各 i=1,2,…,N について， r_j<l_iなる 
j の個数を求めると，その総和が求めるx です．
*/