#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    set<int> s;
    vector<int> v = {1, 4, 3, 2, 4, 4, 2, 3, 4, 5};
    for (int n : v)
    {
        if (s.count(n))
        {
            cout << "o elemento " << n << " ja existe no set" << endl;
        }
        s.insert(n);
    }
    cout << "maior:" << " " << *s.rbegin() << endl;
    cout << "menor: " << *s.begin() << endl;
    cout << "existem " << s.size() << " numeros diferentes" << endl;

    for (int h : s)
    {
        cout << h << endl;
    }

    return 0;
}
//.find(x) retorna .end() se n achar, por isso se faz if(s.find(s)!= s.end())