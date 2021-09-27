#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

using namespace std;


int main(){
	int N, R; 
	uint64_t W, H, D, sumM = 0;
	cin >> N >> R;
	for (int i=0; i<N; i++){
		cin >> W >> H >> D;
		sumM = sumM + R*W*H*D;
	}

	cout << sumM; 
	return 0;
}