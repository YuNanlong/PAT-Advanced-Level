/*
 * 此题注意输出时必须保留一位有效数字
 */
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class PolyNode{
public:
    int exp;
    double coe;
    PolyNode(int e, double c);
};

PolyNode::PolyNode(int e, double c)
    :exp(e), coe(c){

}

int main(){
    int N, e;
    double c;
    vector<PolyNode> lhs, rhs, res;
    cin >> N;
    while(N--){
        cin >> e;
        cin >> c;
        lhs.push_back(PolyNode(e, c));
    }
    cin >> N;
    while(N--){
        cin >> e;
        cin >> c;
        rhs.push_back(PolyNode(e, c));
    }
    vector<PolyNode>::iterator li = lhs.begin();
    vector<PolyNode>::iterator ri = rhs.begin();
    while(li != lhs.end() && ri != rhs.end()){
        if(li->exp > ri->exp){
            res.push_back(PolyNode(li->exp, li->coe));
            li++;
        }
        else if(li->exp < ri->exp){
            res.push_back(PolyNode(ri->exp, ri->coe));
            ri++;
        }
        else{
            if(li->coe + ri->coe != 0){
                res.push_back(PolyNode(li->exp, (li->coe + ri->coe)));
            }
            li++;
            ri++;
        }
    }
    if(li != lhs.end()){
        res.insert(res.end(), li, lhs.end());
    }
    if(ri != rhs.end()){
        res.insert(res.end(), ri, rhs.end());
    }
    cout << res.size();
    if(res.size() == 0){
        return 0;
    }
    for(vector<PolyNode>::iterator i = res.begin(); i != res.end(); i++){
        printf(" %d %.1f", i->exp, i->coe);
    }
}
