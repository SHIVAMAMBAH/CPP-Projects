#include <iostream>
#include<vector>
#include<cmath>


static void printSubMatrix(std::vector<std::vector<int>>& vec2D, std::vector<std::vector<float>>& krnl) {
    int inputRows = vec2D.size();
    int inputColumns = vec2D[0].size();

    int kernalRows = krnl.size();
    int kernalColumns = krnl[0].size();

    int outputRows = inputRows - kernalRows + 1;
    int outputColumns = inputColumns - kernalColumns + 1;

    for (int row = 0; row < outputRows; row++) {
        for (int col = 0; col < outputColumns; col++) {
            std::cout << "\n\nSubmatrix starting at" << "(" << row << "," << col << "):\n\n";
            for (int i = row; i < kernalRows + row; i++) {
                for (int j = col; j < kernalColumns + col; j++) {
                    std::cout << vec2D[i][j] << " ";
                }
                std::cout << "\n";
            }
        }
    }
}

static void Convolution(std::vector<std::vector<int>>& vec2D, std::vector<std::vector<float>>& krnl) {

    int inputRows = vec2D.size();
    int inputColumns = vec2D[0].size();

    int kernalRows = krnl.size();
    int kernalColumns = krnl[0].size();

    int outputRows = inputRows - kernalRows + 1;
    int outputColumns = inputColumns - kernalColumns + 1;

    for (int row = 0; row < outputRows; row++) {
        for (int col = 0; col < outputColumns; col++) {
            float sum = 0.0f;
            for (int i = row; i < kernalRows + row; i++) {
                for (int j = col; j < kernalColumns + col; j++) {
                    float value = static_cast<float>(vec2D[i][j]);
                    sum += value * krnl[i - row][j - col];
                }
            }
            std::cout << static_cast<int>(std::floor(sum)) << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int rows = 5;
    int columns = 5;
    std::vector<std::vector<int>> vec2D =
    {
        {25,26,27,28,29,100,120,130,140},
        {31,42,53,64,75,200,120,210,220},
        {30,40,50,60,70,255,200,195,190},
        {10,20,30,40,50,240,145,150,170},
        {12,24,36,48,60,120,125,130,135},
        {80,81,82,83,84,179,169,190,200},
        {30,40,50,60,70,255,200,195,190},
        {12,24,36,48,60,120,125,130,135},
        {25,26,27,28,29,100,120,130,140},
        {30,40,50,60,70,255,200,195,190},
        {12,24,36,48,60,120,125,130,135},
        {30,40,50,60,70,255,200,195,190},
        {25,26,27,28,29,100,120,130,140},
        {25,26,27,28,29,100,120,130,140},
        {31,42,53,64,75,200,120,210,220},
        {30,40,50,60,70,255,200,195,190},
        {10,20,30,40,50,240,145,150,170},
        {12,24,36,48,60,120,125,130,135},
        {80,81,82,83,84,179,169,190,200},
        {30,40,50,60,70,255,200,195,190},
        {12,24,36,48,60,120,125,130,135},
        {25,26,27,28,29,100,120,130,140},
        {30,40,50,60,70,255,200,195,190},
        {12,24,36,48,60,120,125,130,135},
        {30,40,50,60,70,255,200,195,190},
        {25,26,27,28,29,100,120,130,140}
    };
    std::vector<std::vector<float>> krnl =
    {
        {1.0f / 9,1.0f / 9,1.0f / 9},
        {1.0f / 9,1.0f / 9,1.0f / 9},
        {1.0f / 9,1.0f / 9,1.0f / 9}
    };


    printSubMatrix(vec2D, krnl);
    std::cout << "\n\n\n\n";
    Convolution(vec2D, krnl);

    return 0;
}
