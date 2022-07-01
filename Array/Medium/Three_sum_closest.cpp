#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class io
{
public:
    vector<int> takeVectorInput(vector<int> vec, int vectorSize)
    {
        for (int index = 0; index < vectorSize; index++)
        {
            int num;
            cin >> num;
            vec.push_back(num);
        }
        return vec;
    }

    void printVector(vector<int> vec, int vectorSize)
    {
        for (auto index = vec.begin(); index != vec.end(); index++)
            cout << *index << " ";

        cout << endl;
    }
};

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closest_sum = INT_MAX;
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            int first_pointer = i + 1, second_pointer = size - 1, sum = 0;
            while (first_pointer < second_pointer)
            {
                sum = nums[i] + nums[first_pointer] + nums[second_pointer];

                if (closest_sum > abs(target - sum))
                {
                    ans = sum;
                    closest_sum = abs(target - sum);
                }

                if (sum < target)
                {
                    first_pointer++;
                }
                else if (sum > target)
                {
                    second_pointer--;
                }
                else
                    return ans;
            }
        }
        return ans;
    }
};

int main()
{
    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        int vectorSize;
        cin >> vectorSize;

        vector<int> vec;

        io obIo;

        vec = obIo.takeVectorInput(vec, vectorSize);

        int closest_sum, target;
        cin >> target;

        Solution obSol;

        closest_sum = obSol.threeSumClosest(vec, target);
        cout << closest_sum << endl;
    }
    return 0;
}