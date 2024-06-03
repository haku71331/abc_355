//https://atcoder.jp/contests/abc355/tasks/abc355_d

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
