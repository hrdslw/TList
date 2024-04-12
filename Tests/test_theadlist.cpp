#include "../TList/TList.h"
#include "../TList/THeadList.h"
#include "gtest.h"
using namespace std;

TEST(Monom, OperatorEqualTest) {
    TMonom m1(1, 321);
    TMonom m2(1, 321);
    ASSERT_TRUE(m1 == m2);
}

TEST(Monom, OperatorNotEqualTest) {
    TMonom m1(1, 321);
    TMonom m2(2, 322);
    ASSERT_TRUE(m1 != m2);
}

TEST(Monom, OperatorAssignTest) {
    TMonom m1(1, 321);
    TMonom m2;
    m2 = m1;
    ASSERT_EQ(m1.Coeff, m2.Coeff);
    ASSERT_EQ(m1.Index, m2.Index);
}


TEST(HeadList, InsFirstTest) {
    THeadList<TMonom> list;
    TMonom m(1, 321);
    list.InsFirst(m);
    list.Reset();
    ASSERT_EQ(list.GetCurr().Coeff, 1);
    ASSERT_EQ(list.GetCurr().Index, 321);
}

TEST(HeadList, InsLastTest) {
    THeadList<TMonom> list;
    TMonom m(1, 321);
    list.InsLast(m);
    ASSERT_EQ(list.GetCurr().Coeff, 1);
    ASSERT_EQ(list.GetCurr().Index, 321);
}

TEST(HeadList, InsCurrTest) {
    THeadList<TMonom> list;
    TMonom m1(1, 321);
    TMonom m2(2, 322);
    list.InsFirst(m1);
    list.InsCurr(m2);
    list.Reset();
    ASSERT_EQ(list.GetCurr().Coeff, 2);
    ASSERT_EQ(list.GetCurr().Index, 322);
}

TEST(HeadList, DelFirstTest) {
    THeadList<TMonom> list;
    TMonom m(1, 321);
    list.InsFirst(m);
    list.DelFirst();
    ASSERT_TRUE(list.IsEnd());
}

TEST(HeadList, DelCurrTest) {
    THeadList<TMonom> list;
    TMonom m1(1, 321);
    TMonom m2(2, 322);
    list.InsFirst(m1);
    list.InsLast(m2);
    list.Reset();
    list.GoNext();
    list.DelCurr();
    ASSERT_EQ(list.GetLen(), 1);
    list.DelCurr();
    ASSERT_TRUE(list.IsEnd());
}

