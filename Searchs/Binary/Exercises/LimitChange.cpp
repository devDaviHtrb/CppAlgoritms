#include <bits/stdc++.h>
#include <vector>
using namespace std;

// The bool vector it isn't necessary, because if the vector have been used, the function can use iterators

class Solution
{
    bool isBadVersion(int x, vector<bool> array)
    {
        return array[x];
    }

    int findFirstBad(vector<bool>::iterator begin, vector<bool>::iterator end, vector<bool>::iterator begin_original, vector<bool> array)
    {
        int indexBegin = begin - begin_original;
        int indexEnd = end - begin_original;
        if (isBadVersion(indexBegin + 1, array) && !isBadVersion(indexBegin, array))
        {
            return indexBegin + 1;
        }
        if (isBadVersion(indexEnd, array) && !isBadVersion(indexEnd - 1, array))
        {
            return indexEnd;
        }

        auto mid = begin + (end - begin) / 2;
        if (isBadVersion(mid - begin_original, array))
            return findFirstBad(begin, mid, begin_original, array);
        else
            return findFirstBad(mid + 1, end, begin_original, array);
    }

public:
    int firstBadVersion(int n, vector<bool> array)
    {
        return findFirstBad(array.begin(), array.end(), array.begin(), array);
    }
};