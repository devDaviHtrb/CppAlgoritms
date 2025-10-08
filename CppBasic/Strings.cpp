#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);

    string nome = "abacate"; /*mais lento, poreém com mais metodos*/

    cout << nome;

    char nome2[8] = "abacate";
    cout << nome2 << '\n';

    int cont = 7;
    while (cont > 0)
    {
        nome[cont] = '\0';
        cout << nome << '\n';
        cont--;
    }
}