#include <bits/stdc++.h>

using namespace std;

const int MAX = 60;

typedef long long ll;
struct data {
	ll idx;
	int pos;
	bool operator < (const data x) {
		return idx < x.idx;
	}
} stt[34000000];

int Count;
vector <ll> a, f;
ll S;
ll c[34000000];
int N;

ifstream f_in("in.txt");
ofstream f_out("out.txt");

ll parseInt(string s) {
	ll sum = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != '.') sum = 1LL*sum*10L + s[i] - 48;
	return sum;
}

void enter_data() {
	string str;
	f_in >> str;	f_in >> str;	f_in >> str;
	f_in >> str;	S = parseInt(str);
	while (!f_in.eof()) {
		f_in >> str;
		a.push_back(parseInt(str));
	}
}

void print(int k1, int k2) {
    int tt = 0;
	for (int t = 1; t <= a.size()/2; t++)
		if ((k1 >> (t-1)) & 1) tt++;
	for (int t = 1; t <= N; t++)
		if ((k2 >> (t-1)) & 1) tt++;
    f_out << "#" << ++Count << "-" << tt << ": ";
	for (int t = 1; t <= a.size()/2; t++)
		if ((k1 >> (t-1)) & 1) f_out << a[t-1] << " ";
	for (int t = 1; t <= N; t++)
		if ((k2 >> (t-1)) & 1) f_out << f[t-1] << " ";
	f_out << endl;
}

void process() {
    a.pop_back();
	N = a.size();
	int nStt_1 = 1 << (N / 2);
	nStt_1--;
	for (int i = 0; i <= nStt_1; i++) {
		stt[i].pos = i;
		for (int j = 1; j <= N/2; j++)
			if ((i >> (j-1)) & 1) stt[i].idx += a[j-1];
	}
	sort(stt, stt + nStt_1 + 1);
	for (int i = 0; i <= nStt_1; i++) c[i] = stt[i].idx;
	for (int i = N/2; i < N; i++) f.push_back(a[i]);
	N = f.size();	int nStt_2 = 1 << N;	nStt_2--;
	for (int i = 0; i <= nStt_2; i++) {
		ll x = 0;
		for (int j = 1; j <= N; j++)
			if ((i >> (j-1)) & 1) x += f[j-1];
		if (x > S) continue;
		int p = lower_bound(c, c + nStt_1 + 1, S - x) - c;
		ll y = c[p];
		if (y != S - x) continue;
		while (c[p] == y) {
			print(stt[p].pos, i);
			p++;
		}
	}
}

int main() {
	enter_data();
	process();
	f_out << "There are " << Count << " subset whose sum is equal to " << S << ".";
	f_out << endl << "eof.";
	return 0;
}
