#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> Search(vector<int>::iterator begin_original, vector<int>::iterator begin, vector<int>::iterator end, int target)
    {
        int sum = *begin + *(end - 1);
        if (sum == target)
        {
            int index1 = begin - begin_original + 1;
            int index2 = end - begin_original;
            vector<int> response = {index1, index2};
            return response;
        }
        else if (sum < target)
            return Search(begin_original, begin + 1, end, target);
        else
            return Search(begin_original, begin, end - 1, target);
    }

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        return Search(numbers.begin(), numbers.begin(), numbers.end(), target);
    }
};