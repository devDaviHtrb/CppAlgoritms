#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);

    string name = "abacate"; /*mais lento, poreém com mais metodos*/

    cout << name;

    char name2[8] = "abacate";
    cout << name2 << '\n';

    int cont = 7;
    while (cont > 0)
    {
        name[cont] = '\0';
        cout << name << '\n';
        cont--;
    }
}