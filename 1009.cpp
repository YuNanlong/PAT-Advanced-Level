/*
 * 最后输出四舍五入保留一位小数时可能会出现0.0的情况，0.0是不能输出的
 */
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class PolyNode{
public:
	int exp;
	double coe;
	PolyNode(int e, double c);
	PolyNode();
};

PolyNode::PolyNode()
	:exp(0), coe(0){}

PolyNode::PolyNode(int e, double c)
	:exp(e), coe(c){}

int main(){
	vector<PolyNode> lhs, rhs;
	int K, e;
	double c;
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> e >> c;
		lhs.push_back(PolyNode(e, c));
	}
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> e >> c;
		rhs.push_back(PolyNode(e, c));
	}
	int polyLength = lhs.front().exp + rhs.front().exp - lhs.back().exp - rhs.back().exp + 1;
	PolyNode *res = new PolyNode[polyLength];
	int base = lhs.front().exp + rhs.front().exp;
	for(vector<PolyNode>::iterator i = lhs.begin(); i != lhs.end(); i++){
		for(vector<PolyNode>::iterator j = rhs.begin(); j != rhs.end(); j++){
			e = i->exp + j->exp;
			c = i->coe * j->coe;
			res[base - e].coe += c;
		}
	}
	int count = 0;
	for(int i = 0; i < polyLength; i++){
		if(res[i].coe < 0.5 && res[i].coe > -0.5){
			continue;
		}
		count++;
	}
	cout << count;
	for(int i = 0; i < polyLength; i++){
		if(res[i].coe < 0.5 && res[i].coe > -0.5){
			continue;
		}
		printf(" %d %.1f", base - i, res[i].coe);
	}
}

