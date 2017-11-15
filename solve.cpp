#include "bits/stdc++.h"
#include "Windows.h"

using namespace std;

int aaaa, bbbb;

inline bool isrp(int a, int b){
	if(a <=0 || b<=0 || a==b){   // 互质整数不能小于或等于0
		return false;
	}else if(a==1 || b==1){  // 两个正整数中，只有其中一个数值为1，两个正整数为互质数
		return true;
	}else{
		//  求出两个正整数的最大公约数
		while(1){
			int t = a%b;
			if(t == 0){
				break;
			}else{
				a = b;
				b = t;
			}
		}
		if( b > 1){  // 如果最大公约数大于1，表示两个正整数不互质
			return false;
		}else{         // 如果最大公约数等于1,表示两个正整数互质
			return true;
		}
	}
}

inline int maxx(int a, int b) {
	return a<b ? a : b;
}

inline solve(int a, int b) {
	int aa=a, bb=b;
	register int aaa = maxx(a, b);
	for(register int i=1; i<=maxx(a, b); ++i) {
		if(a%i==0 && b%i==0) {
			a /= i;
			b /= i;
		}
	}
	if(!isrp(a, b)) solve(a, b);

	else cout << a << ':' << b << endl << "--------------------" << endl;
}

int main() {
	freopen("input.log", "r", stdin);
	freopen("output.log", "w", stdout);
	ios::sync_with_stdio(false);

	unsigned int a, b;

	for(;;) {
		while(cin >> a >> b) {
			solve(a, b);
		}
	}

	system("echo finish working!");
}