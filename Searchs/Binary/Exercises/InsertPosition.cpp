#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int BinarySearch(vector<int>::iterator begin_original, vector<int>::iterator begin, vector<int>::iterator end, int x)
    {
        if (begin >= end)
            return end - begin_original;

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

public:
    int searchInsert(vector<int> &nums, int target)
    {
        return BinarySearch(nums.begin(), nums.begin(), nums.end(), target);
    }
};