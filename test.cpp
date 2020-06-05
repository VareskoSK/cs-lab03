#include "histogram.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void
test_same()
{
    double min = 0;
    double max = 0;
    find_minmax({3, 3, 3}, min, max);
    assert(min == 3);
    assert(max == 3);
}
void
test_onenumber()
{
    double min = 0;
    double max = 0;
    find_minmax({2}, min, max);
    assert(min == 2);
    assert(max == 2);
}
void
test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
}

void test_check_height_false ()
{
    size_t bin_height = 5;
    size_t bin_count = 2;
    size_t IMAGE_HEIGHT = 15;
    assert(check_height(bin_height, bin_count, IMAGE_HEIGHT) == false);
}

void test_check_height_true ()
{
    size_t bin_height = 5;
    size_t bin_count = 5;
    size_t IMAGE_HEIGHT = 15;
    assert(check_height(bin_height, bin_count, IMAGE_HEIGHT) == true);
}

int
main()
{
    test_positive();
    test_negative();
    test_same();
    test_onenumber();
    test_empty();
    test_check_height_false();
    test_check_height_true();

}
