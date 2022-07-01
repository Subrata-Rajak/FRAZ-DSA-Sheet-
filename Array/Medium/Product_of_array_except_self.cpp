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

    void printVector(vector<int> vec)
    {
        for (auto index = vec.begin(); index != vec.end(); index++)
            cout << *index << " ";

        cout << endl;
    }
};

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size(), zero_count = 0;
        long long product = 1;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                zero_count++;
            }
            if (nums[i] != 0)
            {
                product *= nums[i];
            }
        }

        vector<int> product_array;

        for (int i = 0; i < size; i++)
        {
            if (zero_count == 1)
            {
                if (nums[i] == 0)
                {
                    product_array.push_back(product);
                }
                else
                {
                    product_array.push_back(0);
                }
            }
            else if (zero_count > 1)
            {
                product_array.push_back(0);
            }
            else
            {
                product_array.push_back(product / nums[i]);
            }
        }

        return product_array;
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

        Solution obSol;

        vector<int> product_array;

        product_array = obSol.productExceptSelf(vec);
        obIo.printVector(product_array);
    }
    return 0;
}