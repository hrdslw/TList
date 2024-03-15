#pragma once
#include "TList.h"

class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom(int monoms[][2] = NULL, int km = 0);

};

