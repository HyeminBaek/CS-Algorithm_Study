#include <iostream>
#include <cstring>

const int MAX = 101;
using namespace std;

int n;
int arr[MAX];

int main(int argc, char **argv)
{
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(arr, 0, sizeof(arr));
        cin >> n;

        int x;
        int left = MAX, right = 0;
        for (int i = 0; i < MAX-1; i++)
        {
            cin >> x;
            arr[x]++;
            if (x < left)
                left = x;
               
            if (right < x)
                right = x;
        }

        while (left < right)
        {
            if (n < arr[left] || n < arr[right])
                break;

            if (arr[left] <= arr[right]){
                arr[left + 1] += arr[left];
                arr[right-1] += arr[left];
                arr[right] -= arr[left];
                
                n -= arr[left];
                arr[left] = 0;
                left++;
            }
            else{
                arr[right - 1] += arr[right];
                arr[left + 1] += arr[right];
                arr[left] -= arr[right];
                
                n -= arr[right];
                arr[right] = 0;
                right--;
            }
        }

        cout << "#" << test_case << " ";
        if (left < right)
            cout << right - left-1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}