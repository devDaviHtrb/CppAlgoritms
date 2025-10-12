#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>::iterator begin_original, vector<int>::iterator begin, vector<int>::iterator end, int x)
{
    if (begin >= end)
        return -1;

    auto mid = begin + (end - begin) / 2;
    if (*mid == x)
    {
        return mid - begin_original;
    }
    else
    {
        if (*mid < x)
        {
            return BinarySearch(begin_original, mid + 1, end, x);
        }
        else
        {
            return BinarySearch(begin_original, begin, mid, x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> vetor = {0, 1, 2, 3, 4, 5, 6};
    cout << BinarySearch(vetor.begin(), vetor.begin(), vetor.end(), 5);
};