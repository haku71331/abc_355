//https://atcoder.jp/contests/abc355/tasks/abc355_b
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<int> vec;//C
    vector<int> vecA;//A
    int n,m,a,b;//nはAの数列の要素数、mはBの要素数
    int k = 0;
    string str = "No";

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);//要素をCに格納
        vecA.push_back(a);//要素をAに格納
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b;
        vec.push_back(b);//要素をCに格納
    }

    //入力とpush

    if(vecA.size() <= 1){
        cout << str << endl;
        return 0;
    }//Aの要素数が1以下なら必ずNoになる

    sort(vec.begin(),vec.end());
    sort(vecA.begin(),vecA.end());

    for (int i = 1; i < n+m; i++)
    {
        if(vec[i-1] == vecA[k]){
            if (vec[i] == vecA[k+1])
            {
                str = "Yes";
            }
        }else if(vec[i-1] > vecA[k])
        {
            k++;
        }
        
    }

    cout << str << endl;
    return 0;
}