#include <iostream>
#include <string>
using namespace std;
int main(){
	string id, inTime, outTime;
	string unlock = "23:59:59", lock = "00:00:00", unlockId, lockId;
	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> id >> inTime >> outTime;
		if(inTime.compare(unlock) < 0){
			unlock = inTime;
			unlockId = id;
		}
		if(outTime.compare(lock) > 0){
			lock = outTime;
			lockId = id;
		}
	}
	cout << unlockId << " " << lockId;
}
