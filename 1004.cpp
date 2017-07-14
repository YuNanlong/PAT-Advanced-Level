#include <iostream>
#include <vector>
using namespace std;
int result[101];
int level = 0, maxLevel = 0;
vector<int> tree[101];

void countLeaf(int rid){
    if(tree[rid].size() == 0){
        result[level]++; 
        return;
    }
    level++;
    if(level > maxLevel){
        maxLevel = level;
    }
    for(vector<int>::iterator i = tree[rid].begin(); i != tree[rid].end(); i++){
        countLeaf(*i);
    }
    level--;
}

int main(){
    int N, M, id, cnum, cid;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> id >> cnum;
        for(int j = 0; j < cnum; j++){
            cin >> cid;
            tree[id].push_back(cid);
        }
    }
    countLeaf(1);
    for(int i = 0; i <= maxLevel; i++){
        if(i != 0){
            cout << " ";
        }
        cout << result[i];
    }
}
