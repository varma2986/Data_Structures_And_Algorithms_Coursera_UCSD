#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::map;
using std::pair;
using std::reverse;

void countSymbols(const string& text, map<char, int>& CharCount, vector<int>& TimesOfOccurence, int& DSymbolPos) {
	int ANumCount = 0;
	int CNumCount = 0;
	int GNumCount = 0;
	int TNumCount = 0;
	int DNumCount = 0;
	for (int i = 0; i < text.size(); i++) {
		char symbol = text[i];
		if (symbol == 'A') {
			TimesOfOccurence.push_back(ANumCount);
			ANumCount++;
		} else if (symbol == 'C') {
			TimesOfOccurence.push_back(CNumCount);
			CNumCount++;
		} else if (symbol == 'G') {
			TimesOfOccurence.push_back(GNumCount);
			GNumCount++;
		} else if (symbol == 'T') {
			TimesOfOccurence.push_back(TNumCount);
			TNumCount++;
		} else if (symbol == '$') {
			DSymbolPos = i;
			TimesOfOccurence.push_back(DNumCount);
			DNumCount++;
		}
	}
	CharCount['$'] = 0;
	CharCount['A'] = DNumCount;
	CharCount['C'] = CharCount['A'] + ANumCount;
	CharCount['G'] = CharCount['C'] + CNumCount;
	CharCount['T'] = CharCount['G'] + GNumCount;
}

string InverseBWT(const string& bwt) {
	string text = "";
	map<char, int> CharCount;
	vector<int> TimesOfOccurence;
	int DSymbolPos = 0;
	countSymbols(bwt, CharCount, TimesOfOccurence, DSymbolPos);

	int lastColIdx = DSymbolPos;

	for (int i = 0; i < bwt.size(); i++)
	{
		text += bwt[lastColIdx];
		lastColIdx = CharCount[bwt[lastColIdx]] + TimesOfOccurence[lastColIdx];
	}
	reverse(text.begin(), text.end());
	return text;
}

int main() {
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;
	return 0;
}


