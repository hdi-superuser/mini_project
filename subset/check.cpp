#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll parseInt(string s) {
	ll sum = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != '.') sum = 1LL*sum*10L + s[i] - 48;
	return sum;
}

void check() {
    ifstream f_in("in.txt");
    ifstream f_check("out.txt");
    ofstream f_log("log.txt");
    string str;
    str = "";
    f_in >> str;
    f_in >> str;
    f_in >> str;
    f_in >> str;
    ll S = parseInt(str);
    ll temp = 0;
    int cnt = 0, ok = 0;
    while (str != "eof.") {
        f_check >> str;
        if (str[0] == 'T') break;
        int n = 0;
        int p = str.find('-');
        for (int i = p+1; i < str.size()-1; i++) n = n*10 + str[i] - 48;
        ll x;
        temp = 0;
        for (int i = 1; i <= n; i++) {
            f_check >> x;
            temp += x;
        }
        f_log << "#" << ++cnt << ": ";
        if (temp == S) f_log << "Ok" << endl, ok++;
        else f_log << "Wrong" << endl;
    }
    f_log << ok << " ok, " << cnt - ok << " wrong.";
    f_log << endl << "eof.";
}

int main() {
    check();
    return 0;
}
