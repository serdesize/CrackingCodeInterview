#pragma once
#include <string>

using namespace std;

class RegularExpressionMatchMaking 
{
public:
	bool isMatch(string s, string p) {

		cout << "input : " << s << endl;
		cout << "pattern : " << p << endl;

		if (p.empty()) return s.empty();

		// handle the easy matches eg. (same char and .)
		bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));

		// handle the complex case
		// we remove the first match because there could be 0 char there
		// if it fails we try with the second 
		if (p.length() >= 2 && p[1] == '*')
			return isMatch(s, p.substr(2)) || firstMatch && isMatch(s.substr(1), p);

		return firstMatch && isMatch(s.substr(1), p.substr(1));
	}
};