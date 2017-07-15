#include <iostream>
using namespace std;
string num[10] = {"zero", "one", "two", "three", "four", \
"five", "six", "seven", "eight", "nine"};
int main(){
	string s;
	cin >> s;
	int sum = 0;
	for(string::iterator i = s.begin(); i != s.end(); i++){
		sum += *i - '0';
	}
	string res = "";
	int temp;
	while(1){
		temp = sum % 10;
		sum /= 10;
		res = num[temp] + res;
		if(sum == 0){
			break;
		}
		else{
			res = " " + res;
		}
	}	
	cout << res;
}
