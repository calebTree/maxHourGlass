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

int maxHourGlass(vector<vector<int>> matrix);
int largest(int matrix[][4]);
int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d);

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << maxHourGlass(arr);
    return 0;
}

int maxHourGlass(vector<vector<int>> glasses) {
    int sums[4][4] = {0};

    sums[0][0] = glassTotal(glasses, 0, 0, 3, 3);
    sums[0][1] = glassTotal(glasses, 0, 1, 4, 3);
    sums[0][2] = glassTotal(glasses, 0, 2, 5, 3);
    sums[0][3] = glassTotal(glasses, 0, 3, 6, 3);

    sums[1][0] = glassTotal(glasses, 1, 0, 3, 4);
    sums[1][1] = glassTotal(glasses, 1, 1, 4, 4);
    sums[1][2] = glassTotal(glasses, 1, 2, 5, 4);
    sums[1][3] = glassTotal(glasses, 1, 3, 6, 4);

    sums[2][0] = glassTotal(glasses, 2, 0, 3, 5);
    sums[2][1] = glassTotal(glasses, 2, 1, 4, 5);
    sums[2][2] = glassTotal(glasses, 2, 2, 5, 5);
    sums[2][3] = glassTotal(glasses, 2, 3, 6, 5);

    sums[3][0] = glassTotal(glasses, 3, 0, 3, 6);
    sums[3][1] = glassTotal(glasses, 3, 1, 4, 6);
    sums[3][2] = glassTotal(glasses, 3, 2, 5, 6);
    sums[3][3] = glassTotal(glasses, 3, 3, 6, 6);

    return largest(sums);

}

int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d) {
    int value = 0;
    int a = 0;
    for (int i = p; i < d; i++) {
        if (a == 1) {
            value += matrix[p+1][q+1];
            a = 0;
            continue;
        }
        for (int j = q; j < r; j++) {
            value += matrix[i][j];
        }
        a++;
    }
    return value;
}

int largest(int matrix[][4]) {
    int maxGlass = matrix[0][0];
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++)
            if (maxGlass < matrix[row][col])
                maxGlass = matrix[row][col];
    }
    return maxGlass;
}