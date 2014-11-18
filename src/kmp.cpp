#include <iostream>
#include <string>
#include <vector>

using namespace std;

void KMP(vector<int> pat, vector<int> txt) {
	int len = 0;
	int i = 1; 
	vector<int> lps(pat.size(), 0);
	while (i < pat.size()) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0)
				len = lps[len-1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
	
	int j = 0;
	i = 0;
	while (i < txt.size()) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == pat.size()) {
			cout << "Match at index " << i-j << endl;
			j = lps[j-1];
		}
		else if (i < txt.size() && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
}

int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";

	vector<int> txtv(txt.begin(), txt.end());
	vector<int> patv(pat.begin(), pat.end());

	KMP(patv, txtv);
	return 0;
}