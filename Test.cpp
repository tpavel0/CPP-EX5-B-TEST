#include "doctest.h"
#include <iostream>
#include <vector>
#include <limits>

#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"

using namespace itertools;
using namespace std;
TEST_CASE("1")
{
    int j = 10;
    CHECK( j != 0 );
    CHECK( j != 1 );
    CHECK( j != 2 );
    CHECK( j != 3 );
    CHECK( j != 4 );
    CHECK( j != 5 );
    CHECK( j != 6 );
    CHECK( j != 7 );
    CHECK( j != 8 );
    CHECK( j != 9 );
    CHECK( j == 10 );
    CHECK( j != 11 );
    CHECK( j != 12 );
    CHECK( j != 13 );
    CHECK( j != 14 );
    CHECK( j != 15 );
    CHECK( j != 130 );
    CHECK( j != 10000 );
    CHECK( j != 20 );
    for(int i : range(4,9)){
                CHECK( j == i );
                CHECK( j+1 != i );
                CHECK( j-1 != i );
                CHECK( j == i );
                CHECK( j == i );
                CHECK( j+1 != i );
                CHECK( j-1 != i );
        j++;
    }
}
TEST_CASE("2")
{
    int j[] = {10, 10+11, 10+11+12, 10+11+12+13};
    int a = 0;
    for (int i: accumulate(range(10, 14))) 
    {
                CHECK(j[a] == i);
        a++;
                CHECK(j[a] + 1 != i);
                CHECK(j[a] - 1 != i);

    }
}


TEST_CASE("3")
{
    int j = 1;
    for(int i : range(5,9))
    {
        CHECK( j == i );
        CHECK( j+1 != i );
        CHECK( j-1 != i );
        j++;
    }
}

TEST_CASE("4")
{
    vector<int> result = {5,7};
    int j = 0;
    for (auto i: filterfalse([](int i){return i%2==0;}, range(5,9)) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 2);


    result.clear();
    j = 0;

    result = {6,8};
    for (auto i: filterfalse([](int i){return i%2!=0;}, range(5,9)) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 2);


    result.clear();
    j = 0;
    result = {3,4,5,7,8};
    set<int> myset = {3,4,5,6,7,8};
    for (auto i: filterfalse([](int i){return i==6;}, myset) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 5);


    result.clear();
    j = 0;
    result = {-99,-20,-2,-1,0};
    set<int> myset2 = {-20,-2,-1,0,1,3,4,5,6,7,8,20,30,40,50,60,70,72,80,90,-99,100};
    for (auto i: filterfalse([](int i){return i > 0;}, myset2) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 5);

    result.clear();
    j = 0;
    result = {-99};
    set<int> myset3 = {-20,-2,-1,0,1,3,4,5,6,7,8,20,30,40,50,60,70,72,80,90,-99,100};
    for (auto i: filterfalse([](int i){return i > -99;}, myset2) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 1);


    result.clear();
    j = 0;
    result = {};
    set<int> myset4 = {-20,-2,-1,0,1,3,4,5,6,7,8,20,30,40,50,60,70,72,80,90,-99,100};
    for (auto i: filterfalse([](int i){return i >= -99;}, myset2) )
    {
        CHECK(0 == 1); // not need to get in
        ++j;
    }
    CHECK(j == 0);


    

}
