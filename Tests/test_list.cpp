#include "../TList/TList.h"
#include "gtest.h"
using namespace std;


TEST(ListTest, CopyConstructorTest) {
    TList<int> list1;
    list1.InsFirst(1);
    list1.InsLast(2);
    TList<int> list2(list1); 
    list2.Reset();
    ASSERT_EQ(list2.GetCurr(), 1);
    list2.GoNext();
    ASSERT_EQ(list2.GetCurr(), 2);
}

TEST(List, InsFirstTest) {
    TList<int> list;
    list.InsFirst(1);
    ASSERT_EQ(list.GetFirst(), 1);
}

TEST(List, InsLastTest) {
    TList<int> list;
    list.InsLast(1);
    ASSERT_EQ(list.GetLast(), 1);
}

TEST(List, InsCurrTest) {
    TList<int> list;
    list.InsCurr(1);
    ASSERT_EQ(list.GetCurr(), 1);
}

TEST(List, DelFirstTest) {
    TList<int> list;
    list.InsFirst(1);
    list.DelFirst();
    ASSERT_TRUE(list.IsEnd());
}

TEST(List, DelCurrTest) {
    TList<int> list;
    list.InsFirst(1);
    list.DelCurr();
    ASSERT_TRUE(list.IsEnd());
}

TEST(List, DelListTest) {
    TList<int> list;
    list.InsFirst(1);
    list.DelList();
    ASSERT_TRUE(list.IsEnd());
}

TEST(List, SetPosTest) {
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.SetPos(1);
    ASSERT_EQ(list.GetCurr(), 2);
}