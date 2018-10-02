#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vt vector<tup>
#define vtt vector<vt >
#define vii vector<vi >
#define viii vector<vii >
#define vb vector<bool>
#define vd vector<double>
#define vbb vector<vb >
#define vl vector<long long int>
#define vll vector<vl >
#define vlll vector<vll >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define fok(x) for (int k = 0; k < x; ++k)
#define foi1(x) for (int i = 1; i <= x; ++i)
#define foj1(x) for (int j = 1; j <= x; ++j)
#define si size()
#define le length()

int n;
int h[51][51];
bool is[51][51];
int r, c;
int mh;


bool isInside(int i, int j, int curr){
	return (i>=0 and j>=0 and i<r and j<c and h[i][j]==curr)?true:false;
}

void setInf(int i, int j, int curr){
	h[i][j]++;
	is[i][j] = 1;
	if(isInside(i+1, j, curr))
		setInf(i+1, j, curr);
	if(isInside(i-1, j, curr))
		setInf(i-1, j, curr);
	if(isInside(i, j+1, curr))
		setInf(i, j+1, curr);
	if(isInside(i, j-1, curr))
		setInf(i, j-1, curr);
}

int main(){
	int tc;
	cin>>tc;
	for(int test_case = 1; test_case <= tc; test_case++){
		printf("Case #%d: ", test_case);
		cin>>r>>c;
		mh = 1;
		int min_val = 10000;
		foi(r){
			foj(c){
				cin>>h[i][j];
				mh = max(mh, h[i][j]);
				min_val = min(min_val, h[i][j]);
			}
		}
		int ans = 0;
		int curr = min_val;

		while(curr < mh){
			memset(is, false, sizeof(is));
			foj(c){
				if(h[0][j] == curr){
					setInf(0, j, curr);
				}
				if(h[r-1][j] == curr){
					setInf(r-1, j, curr);
				}
			}
			foi(r){
				if(h[i][0] == curr){
					setInf(i, 0, curr);
				}
				if(h[i][c-1] == curr){
					setInf(i, c-1, curr);
				}
			}
			foi(r){
				foj(c){
					if(h[i][j] == curr and !is[i][j]){
						h[i][j]++;
						ans++;
					}
				}
			}
			curr++;
		}
		cout<<ans<<endl;
	}
	return 0;
}