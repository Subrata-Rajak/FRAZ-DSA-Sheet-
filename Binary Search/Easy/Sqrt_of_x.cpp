#include <iostream>
using namespace std;

class solution
{
public:
    int mySqrt(int x)
    {
        int low = 1, high = x;

        while (low < high)
        {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        long long ans = (low + high) / 2;

        if (ans * ans > x)
            return ans - 1;
        else
            return ans;
    }
};

int main()
{
    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        int x;
        cin >> x;

        solution obSol;
        int sqrt = obSol.mySqrt(x);
        cout << sqrt << endl;
    }
    return 0;
}