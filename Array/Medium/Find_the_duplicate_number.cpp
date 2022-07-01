#include <iostream>
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
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size() - 1, cnt, size = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;

            for (int n : nums)
            {
                if (n <= mid)
                    cnt++;
            }

            if (cnt <= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
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

        int duplicate;

        Solution obSol;

        duplicate = obSol.findDuplicate(vec);
        cout << duplicate << endl;
    }
    return 0;
}