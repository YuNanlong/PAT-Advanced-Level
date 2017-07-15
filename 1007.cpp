/*
 * 最后输出的是最长子序列的第一个和最后一个值，而不是第一个和最后一个值的下标
 * 应该注意循环变量在循环中会被改变，尽量不要将存储输入用的变量作为循环变量，
 * 如本题中的K，如果循环使用while(K--)，这样在第38行end == K - 1这个条件就
 * 无法判断end是否被改变，因为K在循环中已经被改变了，也就无法区分{-1, -1, -1}, {-1, -1, 0}这样两种情况了
 */
#include <iostream>
using namespace std;
int a[10001];
int main(){
	int K;
	cin >> K;
	int sum = 0, max = 0, begin = 0, end = K - 1, i = -1, j = -1;
	while(j != K - 1){
		j++;
		cin >> a[j];
		if(a[j] >= 0){
			sum += a[j];
			if(i == -1){
				i = j;
			}
		}
		else{
			if(sum + a[j] >= 0){
				sum += a[j];
			}
			else{
				sum = 0;
				i = -1;
			}
		}
		if(sum > max){
			max = sum;
			begin = i;
			end = j;
		}
		else if(sum == max){
			if(begin == 0 && end == K - 1 && a[j] >= 0){
				begin = i;
				end = j;
			}
		}
	}
	cout << max << " " << a[begin] << " " << a[end];
}

