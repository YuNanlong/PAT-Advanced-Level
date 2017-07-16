#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int choice;
	double odd, max, multi = 1;
	for(int i = 0; i < 3; i++){
		max = 0;
		for(int j = 0; j < 3; j++){
			cin >> odd;
			if(odd > max){
				max = odd;
				choice = j;
			}
		}
		multi *= max;
		if(choice == 0){
			cout << "W ";
		}
		else if(choice == 1){
			cout << "T ";
		}
		else{
			cout << "L ";
		}
	}
	printf("%.2f", (multi * 0.65 - 1.0) * 2.0);
}

