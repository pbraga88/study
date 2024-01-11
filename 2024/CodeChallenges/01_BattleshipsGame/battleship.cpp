#include <iostream>
#include <vector>
#include <string>
#include <functional> // for std::function

std::vector<int> solution(std::vector<std::string> &B) {
    int M = B.size();   // width
    int N = B[0].size();    // height
    std::vector<int> result(3,0);   // Initialize the result vector with zeroes
    // Initialize the visited matrix as vector of NxM filled with 'false' values
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));

    // The Lambda function is defined with std::function, so recursion is allowed
    std::function<int(int, int)> dfs;

    // Note: '[&]' is used to capture function members by reference
    //       '-> int' is used to explicit the return type, since it's a requirement
    //       once the lambda function is assigned to 'std::function'
    dfs = [&](int x, int y) -> int {
        if(x<0 || x>=N || y<0 || y>=M || B[x][y] == '.' || visited[x][y]) {
            return 0;
        }
        visited[x][y] = true;
        return 1 + dfs(x+1, y) + dfs(x-1, y) + dfs(x, y+1) + dfs(x, y-1);
    };

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (B[i][j] == '#' && !visited[i][j]) {
                int size = dfs(i, j);
                if (size >= 1 && size<=3) {
                    result[size -1]++;
                }
            }
        }
    }

    return result;
}


// std::vector<int> solution(std::vector<std::string> &B) {
//     int N = B.size();
//     int M = B[0].size();
//     std::vector<int> result(3, 0); // Initialize the result vector with 0s.
//     std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));

//     // Define the lambda function with std::function to allow recursion.
//     std::function<int(int, int)> dfs;
//     dfs = [&](int x, int y) -> int {
//         if (x < 0 || x >= N || y < 0 || y >= M || B[x][y] == '.' || visited[x][y]) {
//             return 0;
//         }
//         visited[x][y] = true;
//         return 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
//     };

//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < M; ++j) {
//             if (B[i][j] == '#' && !visited[i][j]) {
//                 int size = dfs(i, j);
//                 if (size >= 1 && size <= 3) {
//                     result[size - 1]++;
//                 }
//             }
//         }
//     }

//     return result;
// }

// Example usage:
int main() {
    std::vector<std::string> B1 = {".##.#", "#.#..", "#...#", "#.##."};
    std::vector<int> result1 = solution(B1);
    std::cout<<"result1:"<<std::endl;
    // result1 should be [2, 1, 2]

    std::vector<std::string> B2 = {".#..#", "##..#", "...#."};
    std::vector<int> result2 = solution(B2);
    std::cout<<"result2:"<<std::endl;
    // result2 should be [1, 1, 1]

    std::vector<std::string> B3 = {"##.", "#.#", ".##"};
    std::vector<int> result3 = solution(B3);
    std::cout<<"result3:"<<std::endl;
    // result3 should be [0, 0, 2]

    return 0;
}