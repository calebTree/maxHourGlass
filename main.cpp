#include <iostream>
#include <vector>

using namespace std;

int maxHourGlass(vector<vector<int>>);

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

// calculate max hour glass
int maxHourGlass(vector<vector<int>> glass) {
    int arr[4][4] = {0};
    int value = 0;
    int p = 0, q = 0;
    int maxGlass = 0;
    int g = 3;

    while (g < 6) {
        for (int i  = 0; i < g; i++) {
            for (int j = g - 3; j < g; j++) {
                value += glass[i][j];
            }
        }
        arr[p][q] = value;
        value = 0;
        q++;
        if(q > 3){
            p++;
            q = 0;
        }
        g++;
    }

    //largest element
    maxGlass = arr[0][0]; //Assume first is largest
    for (int row = 0; row < 4; row++) {
        for (int col = 1; col < 4; col++)
            if (maxGlass < arr[row][col])
                maxGlass = arr[row][col];
    }
    return maxGlass;
}
