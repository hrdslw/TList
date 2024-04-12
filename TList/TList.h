#pragma once
#include <iostream>
using namespace std;
template <class T>
struct TNode {
	T val;
	TNode* pNext;
};




template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pStop /*pointer at end of list(=0)*/, * pCurr, * pPr;
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
		pLast->pNext = pStop;
	}

	virtual void InsFirst(T _val) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		if (pFirst == nullptr) {
			pFirst = tmp;
			pLast = tmp;

			pFirst->pNext = pStop;
		}
		else {
			tmp->pNext = pFirst;
			pFirst = tmp;
		}

		pCurr = pFirst;
		pos = 0;
		len++;
	}

	virtual void InsLast(T _val) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pStop;
		if (pLast != nullptr) {
			pLast->pNext = tmp;
			if (pLast == pFirst)
				pFirst->pNext = tmp;
		}
		pLast = tmp;
		if (pFirst == nullptr) {
			pFirst = tmp;
			pCurr = pFirst; // обновляем pCurr, если это первый элемент
			pos = 0;
		}
		len++;
	}

	virtual void InsCurr(T _val) {
		if (pCurr == pFirst) {
			this->InsFirst(_val);
		}
		else if (pCurr == nullptr) {
			this->InsLast(_val);
		}
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

	virtual void DelFirst() {
		if (pFirst != pStop) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			if (pFirst == nullptr) {
				pLast = nullptr;
				pCurr = nullptr;
			}
			else if (pCurr == tmp) {
				pCurr = pFirst;
			}
			len--;
		}
	}

	virtual void DelCurr() {
		if (pCurr == pFirst) {
			this->DelFirst();
		}
		else if (pCurr == pLast) 
			this->DelLast();
		else {
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			len--;
		}
	}

	virtual void DelLast()
	{
		if (len == 0) throw ("list is empty");
		else
		{
			if (pLast == pFirst)
			{
				DelFirst();
			}
			{
				if (pCurr == pLast)
				{
					TNode<T>* tmp = pCurr;
					SetPos(pos - 1);
					delete tmp;
					pCurr->pNext = pStop;
					pLast = pCurr;
					len--;
				}
				else
				{
					int currPosition = pos;
					Reset();
					while (pos != len - 2)
					{
						GoNext();
					}
					pCurr->pNext = pStop;
					delete pLast;
					pLast = pCurr;
					SetPos(currPosition);
					len--;

				}
			}
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

	

	virtual void DelList() {
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
		pCurr = nullptr;
	}

	void SetPos(int position)//
	{
		if (position > len || position < 0)
		{
			throw ("wrong pos");
		}
		Reset();
		while (pos != position)
		{
			GoNext();
		}
	}
	T GetCurr() {
		return pCurr->val;
	}

	T GetFirst() {
		return pFirst->val;
	}

	T GetLast() {
		return pLast->val;
	}

	~TList() {
		this->DelList();
	}

};


