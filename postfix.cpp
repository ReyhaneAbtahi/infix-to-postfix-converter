#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

string make_postfix(string wff) {
	vector<char> signs;
	string temp = wff;
	string postfix;
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == ')') {
			for (int j = i - 1;; j--)
				if (temp[j] == '+' || temp[j] == '-' || temp[j] == '*' || temp[j] == '/' || temp[j] == '^') {
					signs.push_back(temp[j]);
					temp[j] = '0';
				}
				else if (temp[j] == '(') {
					temp[j] = '0';
					break;
				}
				temp[i] = '0';
		}
	for (int i = 0, j = 0; i < wff.size(); i++)
		if (wff[i] >= 48 && wff[i] <= 57) {
			postfix.push_back(wff[i]);
		}
		else if (wff[i] == ')') {
			postfix.push_back(signs[j]);
			j++;
		}
	return postfix;
}

int compute_postfix(string postfix) {
	vector<int> x;
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= 48 && postfix[i] <= 57) {
			x.push_back(postfix[i] - 48);
		}
		else if (postfix[i] == '+') {
			x[x.size() - 2] += x[x.size() - 1];
			x.pop_back();
		}
		else if (postfix[i] == '-') {
			x[x.size() - 2] -= x[x.size() - 1];
			x.pop_back();
		}
		else if (postfix[i] == '*') {
			x[x.size() - 2] *= x[x.size() - 1];
			x.pop_back();
		}
		else if (postfix[i] == '/') {
			x[x.size() - 2] /= x[x.size() - 1];
			x.pop_back();
		}
		else if (postfix[i] == '^') {
			x[x.size() - 2] = pow(x[x.size() - 2], x[x.size() - 1]);
			x.pop_back();
		}
	}
	return x[0];
}

int main() {
	string wff;
	string postfix;
	int result;
	getline(cin, wff);
	postfix = make_postfix(wff);
	result = compute_postfix(postfix);
	cout << postfix << endl
		 << result << endl;
}
//(((6*7)+(1^((6+(7*1))/((6-8)^3))))-8)
//(((7-(2*3))^4)+(9/3))

