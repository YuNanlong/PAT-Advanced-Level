#include <iostream>
using namespace std;
int main(){
	int current = 0, floor, N, time = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> floor;
		if(floor > current){
			time += (floor - current) * 6;
		}
		else{
			time += (current - floor) * 4;
		}
		current = floor;
	}
	cout << time + N * 5;
}
