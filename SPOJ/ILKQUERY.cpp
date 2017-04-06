/* Problem: http://www.spoj.com/problems/ILKQUERY/ */

#include <bits/stdc++.h>
#define set_bit(v, i, b) v |= ((b) << (i))
#define get_bit(v, i) ((v) & (1 << (i)))
#define popcnt(x) __builtin_popcount(x)
#define log2(x) (sizeof(uint)*8 - __builtin_clz(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ull unsigned long long int
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define ii pair<int,int>
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define LIM 1e9

using namespace std;

typedef unsigned int uint;

struct BitmapRank {
	const int bits = sizeof(int)*8;
	vector<int> v;
	vector<int> count;
	
	void resize(int a) {
		v.resize((a+bits-1)/bits, 0);
		count.resize(v.size());
	}
	
	void setBit(int i, int b) {
		set_bit(v[i/bits], i%bits, !!b);
	}

	int getBit(int i) {
		return !!get_bit(v[i/bits], i%bits);
	}
	
	void build_rank(void) {
		count[0] = 0;
		for(int i = 1; i < v.size(); i++) count[i] = count[i-1] + popcnt(v[i-1]);
	}
	
	int rank1(int i) {
		if(i < 0) return 0;
		return count[i/bits] + popcnt(v[i/bits] << (bits - i%bits - 1));
	}
	
	void swap(int i) {
		int temp = getBit(i);
		setBit(i,getBit(i+1));
		setBit(i+1,temp);
	}
	
	int rank0(int i) {
		if(i < 0) return 0;
		return i + 1 - rank1(i);
	}
	
	void imp() {
		for(int i = 0; i < v.size()*bits; i++) cout << getBit(i) << " ";
		cout << endl;
	}
};

struct WaveletMatrix {
	uint height;
	vector<BitmapRank> B;
	vi z;
	
	WaveletMatrix(vi &A) : WaveletMatrix(A, *max_element(A.begin(), A.end()) + 1) {}
	
	WaveletMatrix(vi &A, int sigma) : height(log2(sigma - 1)), z(height), B(height) {
		for(int l = 0; l < height; l++) {
			B[l].resize(A.size());
			for(int i = 0; i < A.size(); i++) {
				B[l].setBit(i, get_bit(A[i], height - l - 1));
			}
			B[l].build_rank();
			vi::iterator it = stable_partition(A.begin(), A.end(), [=](int c) {return not get_bit(c, height - l - 1); });
			z[l] = distance(A.begin(), it);
		}
	}
	
	int rank(int c, int i) {
		int p = -1;
		for(int l = 0; l < height; l++) {
			if(get_bit(c, height - l - 1)) {
				i = z[l] + B[l].rank1(i) - 1;
				p = z[l] + B[l].rank1(p) - 1;
			}
			else {
				i = B[l].rank0(i) - 1;
				p = B[l].rank0(p) - 1;
			}
		}
		return i - p;
	}
	
	void swap(int i) {
		int a, b;
		for(int l = 0; l < height; l++) {
			a = B[l].getBit(i);
			b = B[l].getBit(i+1);
			B[l].swap(i);
			if(!a && !b) i = B[l].rank0(i) - 1;
			if(a && b) i = z[l] + B[l].rank1(i) - 1;
			if(a && !b) {
				B[l].count[i]--;
				break;
			}
			if(!a && b) {
				B[l].count[i]++;
				break;
			}
		}
	}
	
	int quantile(int k, int i, int j) {
		int elemento = 0;
		for(int l = 0; l < height; l++) {
			int c = B[l].rank0(j) - B[l].rank0(i-1);
			if(k <= c) {
				i = B[l].rank0(i-1);
				j = B[l].rank0(j) - 1;
			}
			else {
				k -= c;
				set_bit(elemento, height - l - 1, 1);
				i = z[l] + B[l].rank1(i-1);
				j = z[l] + B[l].rank1(j) - 1;
			}
		}
		return elemento;
	}
	
	void imp() {
		for(int i = 0; i < height; i++) {
			cout << i << endl;
			B[i].imp();
		}
		cout << endl;
	}
};

int main(void) {
	int n, q;
	vi v, v2;
	map<int,int> occur;
	map<int,vi > idx;
	
	scanf("%d %d", &n, &q);
	
	int x;
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		x += LIM;
		v.pb(x);
		//v2.pb(x);
		if(occur.find(x) == occur.end()) occur[x] = 1;
		else occur[x]++;
		idx[x].pb(i);
	}
	
	WaveletMatrix wv(v);
	
	int k, i, l;
	int qt, num;
	for(int z = 0; z < q; z++) {
		scanf("%d %d %d", &k, &i, &l);
		qt = wv.quantile(k, 0, i);
		if(occur[qt] < l) puts("-1");
		else printf("%d\n", idx[qt][l-1]);
	}
	
	return 0;
}