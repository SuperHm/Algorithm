// 华为2017-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

static bool minuss = 0;

class Solution{
public:
	Solution();
	void buildBP(int num);
	void getResult(){ cout << result.c_str() <<endl; }
private:
	vector<int> weights;
	vector<int> leftMax;
	string result;
};

Solution::Solution(){
	weights = { 1, 3, 9, 27, 81 };
	leftMax.resize(5);
	leftMax[0] = weights[0];
	for (int i = 1; i < 5; ++i)
		leftMax[i] = leftMax[i - 1] + weights[i];
}

void Solution::buildBP(int num){
	vector<int>::iterator iter = find(weights.begin(), weights.end(), num);
	if (iter != weights.end()){
		result += to_string(*iter);
		return;
	}
	int first;
	for (first = 0; first < 5; ++first){
		if (num <= leftMax[first]){
			result += to_string(weights[first]);
			if (num > weights[first]){
				result += minuss == 0 ? "+" : "-";
				buildBP(num-weights[first]);
				return;
			}
			else{
				result += minuss == 1 ? "+" : "-";
				minuss=!minuss;
				buildBP(weights[first]-num);
				return;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Solution obj;
	int weightObj;
	cin >> weightObj;
	obj.buildBP(weightObj);
	obj.getResult();

	return 0;
}

