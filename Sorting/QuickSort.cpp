#include <bits/stdc++.h>
using namespace std;

vector<int> QuickSort(vector<int> array)
{
    int size = array.size();
    if (size == 1 || size == 0)
    {
        return array;
    }
    int pivo = array[size / 2];
    vector<int> menores = {};
    vector<int> maiores = {};
    vector<int> iguais = {};
    for (int n = 0; n < size; n++)
    {
        int number = array[n];

        if (number > pivo)
        {
            maiores.push_back(number);
        }
        else
        {
            if (number == pivo)
            {
                iguais.push_back(number);
            }
            else
            {
                menores.push_back(number);
            }
        }
    }
    vector<int> s_menores = QuickSort(menores);
    vector<int> s_maiores = QuickSort(maiores);

    vector<int> result;
    result.reserve(size);

    result.insert(result.end(), s_menores.begin(), s_menores.end());
    result.insert(result.end(), iguais.begin(), iguais.end());
    result.insert(result.end(), s_maiores.begin(), s_maiores.end());
    return result;
}