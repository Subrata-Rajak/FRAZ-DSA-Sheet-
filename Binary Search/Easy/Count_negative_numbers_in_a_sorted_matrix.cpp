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
};

class solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int size = grid.size(), negatives = 0;

        for (int i = 0; i < size; i++)
        {
            int low = 0, high = grid[i].size();

            while (low < high)
            {
                int mid = low + (high - low) / 2;

                if (grid[i][mid] < 0)
                    high = mid;
                else
                    low = mid + 1;
            }

            negatives += (grid[i].size() - high);
        }

        return negatives;
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

        solution obSol;
        int negatives = obSol.countNegatives(vec);

        cout << negatives << endl;
    }
    return 0;
}