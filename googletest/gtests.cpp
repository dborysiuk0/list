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
TEST(myfunc, func_3){
    LinkedList<int> list(10);
    
    EXPECT_EQ(list.empty(), 0);
}
TEST(myfunc, func_4){
    LinkedList<int> list;
    
    EXPECT_EQ(list.empty(), 0);
}
TEST(myfunc, func_5){
    LinkedList<int> list(10);
    
    EXPECT_EQ(list.empty(), 0);
}
TEST(myfunc, func_6){
    LinkedList<int> list(10);
    list.del_index(0);
    
    EXPECT_EQ(list.empty(), 1);
}