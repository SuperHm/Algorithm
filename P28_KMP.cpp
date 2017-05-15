// P28_KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class strMatchKMP{
public:
	int kmpSearch(string src, string pattern,int position);
	void getNext(string pattern);
private:
	vector<int> next;
};

int strMatchKMP::kmpSearch(string src, string pattern,int position){
	int slen = src.size();
	int plen = pattern.size();
	int i = position, j = 0;
	while (i<slen && j<plen){
		if (j==-1 || src[i] == pattern[j]) i++, j++;
		else
			j = next[j];
	}
	if (j >= plen) return i - plen;
	else return -1;
}

void strMatchKMP::getNext(string pattern){
	int plen = pattern.size();
	next.resize(plen);
	int i = 0, j = -1;
	next[i] = -1;
	while (i < plen-1){
		if (j == -1 || pattern[i] == pattern[j]) next[++i] = ++j;
		else
			j = next[j];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string src = "ababcabcacbab";
	string pattern = "abcac";
	strMatchKMP strMatch;
	strMatch.getNext(pattern);
	cout << strMatch.kmpSearch(src, pattern, 0) << endl;
	return 0;
}

