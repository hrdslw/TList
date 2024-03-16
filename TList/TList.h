#pragma once
#include <iostream>

template <class T>
struct TNode {
	T val;
	TNode* pNext;
};




template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pStop /*pointer at end of list(=0)*/, * pCurr, pPr;
	int pos, len;
public:
	TList() {
		pFirst = pLast = pStop = nullptr;
		pPr = pStop;
		pCurr = pFirst;
		pos = -1;
		len = 0;
	}
	TList(const TList& l) {
		TNode<T>* tmp = l.pFirst;
		TNode<T>* i;
		while (tmp != nullptr) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (pFirst == nullptr) {
				pFirst = i;
				pLast = i;
			}
			else {
				pLast->pNext = i;
				pLast = i;
			}
			tmp = tmp->pNext;
		}
		len = l.len;
		pos = -1;
		pStop = nullptr;
	}

	void InsFirst(T _val) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pFirst;
		pFirst = tmp;
		len++;
	}

	void InsLast(T _val) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pStop;
		pLast->pNext = tmp;
		pLast = tmp;
		len++;
	}

	void InsCurr(T _val) {
		if (pCurr == pFirst)
			this->InsFirst(_val);
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp->val = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			len++;
			pos++;
		}
	}

	void Reset() {
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;
	}

	void GoNext() {
		if (pCurr != pStop) {
			pPr = pCurr;
			pCurr = pCurr->pNext;
			pos++;
		}
	}

	bool IsEnd() {
		return (pStop == pCurr);
	}

	void DelFirst() {
		if (pFirst != pStop) {
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr = pStop;
			delete tmp;
			len--;
		}
	}

	void DelCurr() {
		if (pCurr == pFirst)
			this->DelFirst();
		else {
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			l--;
		}
	}

	void DelList() {
		TNode<T>* tmp;
		while (pFirst != pStop) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

	void SetPose(int p) {
		this->Reset();
		int count = 0;
		while (pCurr != pStop) {
			for (int i = 0; i < p; i++)
				this->GoNext();
			count++;
		}
		if (count != p)
		{ /*hz what to do here */ }
	}
	T GetCurr() {
		return pCurr->val;
	}

	~TList() {
		this->DelList();
	}

};

struct TMonom {
	double Coeff;
	int Index; // "x^3 y^2 z^1 -> 321"
public:
	TMonom() {
		Coeff = 0;
		Index = -1;
	}
	TMonom(int a, int b) {
		Coeff = a;
		Index = b;
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
};

template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		//pHead = new TNode<T>;
		pHead = nullptr;
		pHead->pNext = pFirst;
		pStop = pFirst = pPr = pCurr = pLast = pHead;
		pos = -1;
		len = 0;
	}
	THeadList(const THeadList& l) {
		pHead = nullptr;
		TNode<T>* tmp = l.pFirst;
		TNode<T>* i;
		while (tmp != nullptr) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (l.pFirst == l.pHead) {
				pFirst = pLast = pStop = pHead = i;
			}
			else {
				pLast->pNext = i;
				pLast = i;
				pHead->pNext = pFirst;
			}
			tmp = tmp->pNext;
		}
		len = l.len;
		pos = -1;
		pStop = pHead;
		
		// seems right
	}

	~THeadList() {
		TList<T>::DelList();
		delete pHead;
	}

	void InsFirst(T val)  {
		TList<T>::InsFirst(val);
		pHead->pNext = pFirst;
	}

	void InsLast(T val)  {
		TList<T>::InsLast(val);
		pLast->pNext = pHead;
	}

	void InsCurr(T val)   {
		TList<T>::InsCurr(val);
	}

	void DelFirst() {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	void DelCurr()  {
		TList<T>::DelCurr();
	}

	void DelLast()  {
		TList<T>::DelLast();
		pLast->pNext = pHead;
	}

};

