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
const int SUM_SIZE = 4;

int maxHourGlass(vector<vector<int>> matrix);
int largest(int matrix[][SUM_SIZE]);
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
    int sums[4][SUM_SIZE] = {0};
    for (int i = 0; i < SUM_SIZE; i++)
        for (int j = 0; j < SUM_SIZE; j++)
            sums[i][j] = glassTotal(glasses, i, j,j + 3,i + 3);
    return largest(sums);
}

int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d) {
    int value = 0, a = 0;
    for (int i = p; i < d; i++) {
        if (a == 1) {
            value += matrix[p + 1][q + 1];
            a = 0;
            continue;
        }
        for (int j = q; j < r; j++)
            value += matrix[i][j];
        a++;
    }
    return value;
}

int largest(int matrix[][SUM_SIZE]) {
    int maxGlass = matrix[0][0];
    for (int row = 0; row < SUM_SIZE; row++)
        for (int col = 0; col < SUM_SIZE; col++)
            if (maxGlass < matrix[row][col])
                maxGlass = matrix[row][col];
    return maxGlass;
}