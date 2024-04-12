#pragma once
#include "TList.h"
#include "THeadList.h"
#include <iostream>
using namespace std;

class TPolinom : public THeadList<TMonom>
{
	friend ostream& operator<< (ostream& os, TPolinom& p);
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

	TPolinom& operator+ (TPolinom& TP)
	{
		
		(*this).Reset();
		TP.Reset();
		while ((*this).pCurr != (*this).pStop && TP.pCurr != TP.pStop)
		{
			if ((*this).GetCurr().Index < TP.GetCurr().Index)
			{
				(*this).InsCurr(TP.GetCurr());
				TP.GoNext();
			}
			else if ((*this).GetCurr().Index > TP.GetCurr().Index)
				{
					(*this).GoNext();
				}
				else
				{
					(*this).pCurr->val.Coeff = TP.pCurr->val.Coeff + (*this).pCurr->val.Coeff;
					if ((*this).pCurr->val.Coeff != 0)
					{
						TP.GoNext();
						(*this).GoNext();
					}
					else
					{
						(*this).DelCurr();
						TP.GoNext();
					}
				}

		}
		return *this;
	}

	TPolinom& operator* (double c)
	{
		if (c == 0)
		{
			(*this).DelList();
		}
		else
		{

			(*this).Reset();
			while (!(*this).IsEnd())
			{
				(*this).pCurr->val.Coeff = (*this).pCurr->val.Coeff * c;
				(*this).GoNext();
			}
		}
		return *this;
	}

	TPolinom& operator- (TPolinom& TP)
	{
		return (*this + TP * (-1));
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
		if (pCurr == nullptr)
		{
			InsFirst(_m);
		}
		pCurr = pFirst;
		while (_m.Index < pCurr->val.Index) {
			GoNext();
		}
		if (pCurr->val == _m) {
			if (_m.Coeff + pCurr->val.Coeff == 0)
				DelCurr();
			else if (pFirst != pLast)
				pCurr->val.Coeff = _m.Coeff + pCurr->val.Coeff;
		}
		else
			InsCurr(_m);
	}

	void EnterPolinom()
	{
		int i; double c;
		cout << "Введите коэффициент монома:" << endl;
		cin >> c;
		cout << "Введите индекс монома" << endl;
		cin >> i;
		cout << "0 - закончить ввод" << endl;
		if (i < 100) throw ("wrong index");
		while (1)
		{
			TMonom newmonom(c, i);
			AddMonom(newmonom);
			cin >> c;
			if (c == 0) break;
			cin >> i;
			if (i == 0) break;
			if (i < 100) throw ("Неправильный индекс");

		}
	}


	friend ostream& operator<< (ostream& os, TPolinom& p)
	{
		p.Reset();
		int x, y, z;
		x = p.GetCurr().Index / 100;
		y = p.GetCurr().Index % 100 / 10;
		z = p.GetCurr().Index % 10;
		os << p.GetCurr().Coeff << "(x^" << x << " * y^" << y << " * z^" << z << ")";
		p.GoNext();
		while (!p.IsEnd())
		{
			x = p.GetCurr().Index / 100;
			y = p.GetCurr().Index % 100 / 10;
			z = p.GetCurr().Index % 10;
			if (p.GetCurr().Coeff > 0)
				os << " + ";

			os << p.GetCurr().Coeff << "(x^" << x << " * y^" << y << " * z^" << z << ")";
			p.GoNext();
		}
		return os;
	}

};

