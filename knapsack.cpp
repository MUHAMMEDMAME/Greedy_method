#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int weight[5] = {0, 3, 4, 5, 6};
    int value[5] = {0, 2, 3, 4, 1};
    int n = 4, m = 8;
    int k[5][9];
    bool isSelected[5][9] = {false}; // Matrix to track which items are selected

    cout << isSelected[4][8] << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (w >= weight[i])
            {
                k[i][w] = max(value[i] + k[i - 1][w - weight[i]], k[i - 1][w]);
                // Mark the item as selected if it contributes to the maximum value
                if (value[i] + k[i - 1][w - weight[i]] > k[i - 1][w])
                    isSelected[i][w] = true;
            }
            else
                k[i][w] = k[i - 1][w];
        }
    }

    // Printing the table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            cout << k[i][w] << " ";
        }
        cout << endl;
    }

    cout << "\nItems selected:\n";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {

        if (k[i][j] == k[i - 1][j])
        {
            cout << i << ":0" << endl;
            i--;
        }
        else
        {
            cout << i << ":1" << endl;
            i--;
            j = j - weight[i];
        }
    }

    return 0;
}
