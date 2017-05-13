// ��Ϊ2017-2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	vector<int> bp;
	string result;
};

Solution::Solution(){
	weights.push_back(1);
	weights.push_back(3);
	weights.push_back(9);
	weights.push_back(27);
	weights.push_back(81);
	leftMax.resize(5);
	leftMax[0] = weights[0];
	for (int i = 1; i < 5; ++i)
		leftMax[i] = leftMax[i - 1] + weights[i];
	bp.resize(121);
	bp[1] = 1;
	bp[3] = 3;
	bp[9] = 9;
	bp[27] = 27;
	bp[81] = 81;
}

void Solution::buildBP(int num){
	vector<int> init = {1,3,9,27,81};
	vector<int>::iterator iter = find(init.begin(), init.end(), num);
	if (iter != init.end()){
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

