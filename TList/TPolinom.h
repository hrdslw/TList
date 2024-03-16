#pragma once
#include "TList.h"
#include <iostream>
using namespace std;

class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom(int monoms[][2] = NULL, int km = 0) {
		TMonom tmp(0, 1);
		pHead->val = tmp;
		for (int i = 0; i < km; i++) {
			TMonom monom((double)monoms[i][0], monoms[i][1]);
			InsLast(monom);
		}
	}

	TPolinom(TPolinom& TP) {
		TMonom m(0, -1);
		pHead->val = m;
		for (TP.Reset(); !TP.IsEnd(); TP.GoNext()) {
			TMonom monom = TP.GetCurr();
			InsLast(monom);
		}
	}

	TMonom GetMonom() {
		TMonom monom = GetCurr();
		return monom;
	}

	TPolinom& operator+= (TPolinom& q) {
		// P = x^2y^2z^2 + x^1y^1z^1 + ...... + 5
		// Q = x^3y^2z^2 + x^3y^1z^1 + ...... + 3
		// P + Q = 

		TMonom pm, qm, rm;
		this->Reset();
		while (1) {
			pm = GetMonom();
			qm = q.GetMonom();
			if (pm.Index < qm.Index) {
				//monom pm younger than monom qm => add monom qm into P
				InsCurr(qm);
				q.GoNext();
			}
			else if (pm.Index > qm.Index)
				GoNext();
			else {
				// indexes  are equal (but they could pHeads) 
				if (pm.Index == -1)
					break;
				pm.Coeff += qm.Coeff;
				if (pm.Coeff != 0)
				{
					GoNext();
					q.GoNext();
				}
				else {
					// deleting monom with 0-coeff
					DelCurr();
					q.GoNext();
				}
			}
		}
		return *this;
	}

	TPolinom& operator= (TPolinom& TP) {
		DelList();
		for (TP.Reset(); !TP.IsEnd(); TP.GoNext()) {
			TMonom monom = TP.GetCurr();
			InsLast(monom);
		}
		return *this;
	}

	void AddMonom(TMonom _m) {
		pCurr = pFirst;
		while (_m.Index < pCurr->val.Index) {
			GoNext();
		}
		if (pCurr->val == _m) {
			if (_m.Coeff + pCurr->val.Coeff == 0) DelCurr();
			else pCurr->val.Coeff = _m.Coeff + pCurr->val.Coeff;
		}

	}

	/*friend ostream& operator<< (ostream& os, TPolinom& TP) {

	}*/
};

