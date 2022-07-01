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

    vector<vector<int>> take2DVectorInput(vector<vector<int>> vec, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            vector<int> oneDVector;
            for (int j = 0; j < col; j++)
            {
                int temp;
                cin >> temp;
                oneDVector.push_back(temp);
            }
            vec.push_back(oneDVector);
        }

        return vec;
    }

    void print2DVector(vector<vector<int>> vec)
    {
        int row = vec.size(), col = vec[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << vec[row][col] << " ";
            }
            cout << endl;
        }
    }
};

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> sum_vector;

        if (size < 3)
            return sum_vector;

        sort(nums.begin(), nums.end());
        int low, high;

        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            low = i + 1;
            high = size - 1;

            while (low < high)
            {
                int k = nums[i] + nums[low] + nums[high];
                if (k > 0)
                {
                    high -= 1;
                }
                else if (k < 0)
                {
                    low += 1;
                }
                else
                {
                    sum_vector.push_back({nums[i], nums[low], nums[high]});
                    low += 1;
                    while (nums[low] == nums[low - 1] && low < high)
                        low++;
                }
            }
        }
        return sum_vector;
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

        vector<vector<int>> three_sum_array;

        Solution obSol;

        three_sum_array = obSol.threeSum(vec);
        obIo.print2DVector(three_sum_array);
    }
    return 0;
}