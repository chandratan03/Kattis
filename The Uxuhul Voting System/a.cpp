// Meysam Aghighi

#include <iostream>
using namespace std;

// moves with exactly one bit change
const int rel[8][3] = {
	{1,2,4},
	{0,3,5},
	{0,3,6},
	{1,2,7},
	{0,5,6},
	{1,4,7},
	{2,4,7},
	{3,5,6}
};

string print(int x){
    if (x==0) return "NNN"; // even
    if (x==1) return "NNY"; // odd
    if (x==2) return "NYN"; // odd
    if (x==3) return "NYY"; // even
    if (x==4) return "YNN"; // odd
    if (x==5) return "YNY"; // even
    if (x==6) return "YYN"; // even
    if (x==7) return "YYY"; // odd
}

int main(){
	int n,m,t0,t1,t2;
	cin >> n;
	while(n--){
		cin >> m;
		int a[m][8],f[m][8]; // f[i][j] = how voter number i will decide that what happens to number j - at the end!
		for (int i=0;i<m;i++) for (int j=0;j<8;j++) cin >> a[i][j];
		for (int i=0;i<8;i++){
			t0 = a[m-1][rel[i][0]];
			t1 = a[m-1][rel[i][1]];
			t2 = a[m-1][rel[i][2]];
			if (t0 < t1 && t0 < t2) f[m-1][i] = rel[i][0];
			else if (t1 < t2) f[m-1][i] = rel[i][1];
			else f[m-1][i] = rel[i][2];
		}
		for (int k=m-2;k>=0;k--){
			for (int i=0;i<8;i++){
				t0 = a[k][f[k+1][rel[i][0]]];
				t1 = a[k][f[k+1][rel[i][1]]];
				t2 = a[k][f[k+1][rel[i][2]]];
				if (t0 < t1 && t0 < t2) f[k][i] = f[k+1][rel[i][0]];
				else if (t1 < t2) f[k][i] = f[k+1][rel[i][1]];
				else f[k][i] = f[k+1][rel[i][2]];
			}
		}
//		for (int i=0;i<8;i++)
//			cout << print(f[0][i]) << endl;
		cout << print(f[0][0]) << endl;
	}
	return 0;
}
