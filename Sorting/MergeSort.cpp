#include <bits/stdc++.h>
using namespace std;

vector<int> MergeSort(vector<int> array)
{
    int array_size = array.size();
    if (array_size <= 1)
    {
        return array;
    }

    int mid = array_size / 2;
    vector<int>::iterator begin = array.begin();

    vector<int> left(begin, begin + mid);
    vector<int> right(begin + mid, array.end());
    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
};

vector<int> Merge(vector<int> left, vector<int> right)
{

    vector<int> result;
    int i = 0, j = 0;
    int left_size = left.size();
    int right_size = right.size();

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }
    while (i < left.size())
        result.push_back(left[i++]);

    while (j < right.size())
        result.push_back(right[j++]);

    return result;
};

vector<int> RecursiveMerge(vector<int>::iterator left, vector<int>::iterator right, vector<int> &result, vector<int>::iterator left_end, vector<int>::iterator right_end)
{
    if (left == left_end && right == right_end)
        return result;
    if (left == left_end)
    {
        result.push_back(*right);
        right++;
        return RecursiveMerge(left, right, result, left_end, right_end);
    }
    if (right == right_end)
    {
        result.push_back(*left);
        left++;
        return RecursiveMerge(left, right, result, left_end, right_end);
    }
    if (*left <= *right)
    {
        result.push_back(*left);
        left++;
        return RecursiveMerge(left, right, result, left_end, right_end);
    }
    else
    {
        result.push_back(*right);
        right++;
        return RecursiveMerge(left, right, result, left_end, right_end);
    }
}

vector<int> AlternativeMerge(vector<int>::iterator left, vector<int>::iterator right, vector<int> &result, vector<int>::iterator left_end, vector<int>::iterator right_end)
{
    while (right != right_end && left != left_end)
    {
        if (*left <= *right)
        {
            result.push_back(*left);
            left++;
        }
        else
        {
            result.push_back(*right);
            right++;
        }
    }
    while (right != right_end)
    {
        result.push_back(*right);
        right++;
    }
    while (left != left_end)
    {
        result.push_back(*left);
        left++;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}
