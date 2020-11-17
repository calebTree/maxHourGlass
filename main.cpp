#include <iostream>
#include <vector>
/*
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
#19

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 9 2 -4 -4 0
0 0 0 -2 0 0
0 0 -1 -2 -4 0
#13
 */
using namespace std;

const int MATRIX_SIZE = 6;
const int AGGREGATE_MATRIX = MATRIX_SIZE - 2;

int maxHourGlass(vector<vector<int>> matrix);
int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d);

int main()
{
    vector<vector<int>> arr(MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        arr[i].resize(MATRIX_SIZE);
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cin >> arr[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << maxHourGlass(arr);
    return 0;
}

int maxHourGlass(vector<vector<int>> glasses) {
    int glassSum;
    int maxGlass = glassTotal(glasses, 0, 0, 3, 3);         // assume firs glass is maxGlass
    for (int i = 1; i < AGGREGATE_MATRIX; i++)                          // iterate row, start at following glass
        for (int j = 0; j < AGGREGATE_MATRIX; j++) {                    // iterate column
            glassSum = glassTotal(glasses, i, j, i + 3, j + 3);   // sum glass
            if (maxGlass < glassSum)
                maxGlass = glassSum;                                    // set maxGlass if < than previous glassSum
        }
    return maxGlass;
}

int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d) {
    int value = 0, a = 0;
    for (int i = p; i < r; i++) {
        if (a == 1) {
            value += matrix[p + 1][q + 1];
            a = 0;
            continue;
        }
        for (int j = q; j < d; j++)
            value += matrix[i][j];
        a++;
    }
    return value;
}