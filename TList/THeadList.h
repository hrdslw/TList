#include <iostream>
#include "TList.h"

using namespace std;

struct TMonom {
	int Coeff;
	int Index; // "x^3 y^2 z^1 -> 321"
	//friend ostream& operator<< (ostream& os, TMonom m);
public:
	TMonom() {
		Coeff = 0;
		Index = -1;
	}
	TMonom(int a, int b) {
		Coeff = a;
		Index = b;
	}
	void operator= (TMonom& m)
	{
		Coeff = m.Coeff;
		Index = m.Index;
	}
	bool operator ==(TMonom& m) {
		if (Coeff == m.Coeff) {
			if (Index == m.Index)
				return true;
		}
		return false;
	}
	bool operator !=(TMonom& m) {
		if (*this == m)
			return false;
		return true;
	}

	friend ostream& operator<< (ostream& os, TMonom m)
	{
		os << m.Coeff << "\n" << "___\n" << m.Index;
		return os;
	}


};

template <class T>
class THeadList : public TList<TMonom> {
protected:
	TNode<T>* pHead;
public:
	THeadList()
	{
		pHead = new TNode<T>;
		pHead->pNext = pHead;

		pStop = pLast = pFirst = pPr = pCurr = nullptr;
		pos = -1;
		len = 0;
	}
	THeadList(const THeadList& l) {
		pHead = new TNode<T>;
		TNode<T>* tmp = l.pFirst;
		TNode<T>* i;
		while (tmp != nullptr) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (l.pFirst == l.pHead) {
				pFirst = pLast = pStop = pHead = i;
			}
			else {
				pLast = i;
				pLast->pNext = i;	
				pHead->pNext = pFirst;
			}
			tmp = tmp->pNext;
		}
		len = l.len;
		pos = -1;
		pLast->pNext = pStop;
		//pStop = pHead;

		// seems right
	}



	int GetLen() {
		return len;
	}

	~THeadList() {
		TList<T>::DelList();
		delete pHead;
	}

	void InsFirst(T val) {
		TList<T>::InsFirst(val);
		pHead->pNext = pFirst;
	}

	void InsLast(T val) override
	{
		TList<T>::InsLast(val);
		pLast->pNext = pStop;
		//pStop->pNext = pHead;
		pHead->pNext = pFirst;
	}

	void InsCurr(T val) {
		TList<T>::InsCurr(val);
		pHead->pNext = pFirst;
	}

	void DelFirst() override {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	void DelCurr() override {
		TList<T>::DelCurr();
		if (pCurr == pFirst)
		{
			pHead->pNext = pFirst;
		}
	}

	void DelLast() override
	{
		TList<T>::DelLast();
		pLast->pNext = pStop;
		//pStop->pNext = pHead;
		pHead->pNext = pFirst;
	}


};
