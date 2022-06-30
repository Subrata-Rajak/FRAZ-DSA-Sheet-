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

class solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;

        while (start < end)
        {

            int mid = (start + end) / 2;
            if (arr[mid] < arr[mid + 1])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
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

        solution obSol;
        int peakIndex = obSol.peakIndexInMountainArray(vec);
        cout << peakIndex << endl;
    }
    return 0;
}