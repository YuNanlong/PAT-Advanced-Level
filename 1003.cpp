/*
 * 计算从i到j经由k有多少不同的最短路径时，path[i][j] = path[i][k] * path[k][j]，而不是简单的path[i][j] = 1
 * 处理c1 == c2的情况
 */
#include <iostream>
using namespace std;
const int MAX = 65536;
int map[501][501], path[501][501], team[501][501];
int res[501];
int main(){
    for(int i = 0; i < 501; i++){
        for(int j = 0; j < 501; j++){
            map[i][j] = MAX;
        }
    }
    int N, M, c1, c2;
    cin >> N >> M >> c1 >> c2;
    for(int i = 0; i < N; i++){
        cin >> res[i];
    }
    int begin, end, length;
    for(int i = 0; i < M; i++){
        cin >> begin >> end >> length;
        map[begin][end] = map[end][begin] = length;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] > 0 && map[i][j] != MAX){
                path[i][j] = 1;
                team[i][j] = res[i] + res[j];
            }
        }
    }
    if(c1 == c2){
        cout << "1 " << res[c1];
        return 0;
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][k] + map[k][j] < map[i][j]){
                    map[i][j] = map[i][k] + map[k][j]; 
                    path[i][j] = path[i][k] * path[k][j];
                    team[i][j] = team[i][k] + team[k][j] - res[k];
                }
                else if(map[i][k] + map[k][j] == map[i][j]){
                    path[i][j] += path[i][k] * path[k][j];
                    if(team[i][k] + team[k][j] - res[k] > team[i][j]){
                        team[i][j] = team[i][k] + team[k][j] - res[k];
                    }
                }
            }
        }
    }
    cout << path[c1][c2] << " " << team[c1][c2];
}
