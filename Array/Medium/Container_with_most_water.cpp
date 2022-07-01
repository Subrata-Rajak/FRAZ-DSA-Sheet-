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
    int maxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int area = 0;

        while (start < end)
        {
            area = max(area, min(height.at(start), height.at(end)) * (end - start));

            if (height.at(start) < height.at(end))
                start++;

            else
                end--;
        }
        return area;
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

        int max_area_container;

        Solution obSol;

        max_area_container = obSol.maxArea(vec);
        cout << max_area_container << endl;
    }
    return 0;
}