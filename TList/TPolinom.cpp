#include "TPolinom.h"
#include "../TList/TList.h"

TPolinom::TPolinom(int monoms[][2], int km) {
	TMonom tmp(0, 1);
	pHead->val = tmp;
	for (int i = 0; i < km; i++) {
		TMonom monom((double)monoms[i][0], monoms[i][1]);
		InsLast(monom);
	}
}