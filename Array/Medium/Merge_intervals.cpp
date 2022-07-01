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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int size = intervals.size();

        if (size == 0)
            return ans;

        sort(intervals.begin(), intervals.end());

        vector<int> temp = intervals[0];

        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

int main()
{
    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        int row, col;
        cin >> row >> col;

        vector<vector<int>> vec;

        io obIo;

        vec = obIo.take2DVectorInput(vec, row, col);

        vector<vector<int>> merged_intervals;

        Solution obSol;

        merged_intervals = obSol.merge(vec);
        obIo.print2DVector(merged_intervals);
    }
    return 0;
}