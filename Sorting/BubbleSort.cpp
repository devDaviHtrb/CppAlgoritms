#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> array, int end)
{
    if (end == 1)
        return array;

    for (int i = 0; i < end - 1; i++)
    {
        if (array[i] > array[i + 1])
            swap(array[i], array[i + 1]);
    }

    return bubbleSort(array, end - 1);
}

vector<int> recursiveBubbleSort(vector<int> &array, int end, int current_index)
{
    if (end == 1)
        return array;
    if (current_index < end - 1)
    {
        if (array[current_index] > array[current_index + 1])
        {
            swap(array[current_index], array[current_index + 1]);
        }
        return recursiveBubbleSort(array, end, current_index + 1);
    }
    return recursiveBubbleSort(array, end - 1, 0);
}

void alternative_recursive_bbs(vector<int> &array, int end, int current_index)
{
    if (end == 1)
    {
        return;
    }
    if (current_index < end - 1)
    {
        if (array[current_index] > array[current_index + 1])
        {
            swap(array[current_index], array[current_index + 1]);
        }
        return alternative_recursive_bbs(array, end, current_index + 1);
    }
    return alternative_recursive_bbs(array, end - 1, 0);
}