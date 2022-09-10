#include "gtest/gtest.h"
#include "../LinkedList.h"

static int a = 0;
class myclass{
    public:
    myclass(){
        a++;
    }
};
TEST(myfunc, func_0){
    LinkedList<int> list;
    list.push_back(21);
    list.push_front(22);
    EXPECT_EQ(list.size(), 2);
}
TEST(myfunc, func_1){
    LinkedList<myclass> list;
    EXPECT_EQ(a, 0);
}
TEST(myfunc, func_2){
    LinkedList<int> list(10);
    
    EXPECT_EQ(list.size(), 1);
}

// add more tests