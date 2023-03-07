#include "test_push_swap.h"



Test(sort_small_4, args_1)
{
	assert_sort_small("1 2 3 4", "1 2 3 4");
}
          

Test(sort_small_4, args_2)
{
	assert_sort_small("1 2 4 3", "1 2 3 4");
}
          

Test(sort_small_4, args_3)
{
	assert_sort_small("1 3 2 4", "1 2 3 4");
}
          

Test(sort_small_4, args_4)
{
	assert_sort_small("1 3 4 2", "1 2 3 4");
}
          

Test(sort_small_4, args_5)
{
	assert_sort_small("1 4 2 3", "1 2 3 4");
}
          

Test(sort_small_4, args_6)
{
	assert_sort_small("1 4 3 2", "1 2 3 4");
}
          

Test(sort_small_4, args_7)
{
	assert_sort_small("2 1 3 4", "1 2 3 4");
}
          

Test(sort_small_4, args_8)
{
	assert_sort_small("2 1 4 3", "1 2 3 4");
}
          

Test(sort_small_4, args_9)
{
	assert_sort_small("2 3 1 4", "1 2 3 4");
}
          

Test(sort_small_4, args_10)
{
	assert_sort_small("2 3 4 1", "1 2 3 4");
}
          

Test(sort_small_4, args_11)
{
	assert_sort_small("2 4 1 3", "1 2 3 4");
}
          

Test(sort_small_4, args_12)
{
	assert_sort_small("2 4 3 1", "1 2 3 4");
}
          

Test(sort_small_4, args_13)
{
	assert_sort_small("3 1 2 4", "1 2 3 4");
}
          

Test(sort_small_4, args_14)
{
	assert_sort_small("3 1 4 2", "1 2 3 4");
}
          

Test(sort_small_4, args_15)
{
	assert_sort_small("3 2 1 4", "1 2 3 4");
}
          

Test(sort_small_4, args_16)
{
	assert_sort_small("3 2 4 1", "1 2 3 4");
}
          

Test(sort_small_4, args_17)
{
	assert_sort_small("3 4 1 2", "1 2 3 4");
}
          

Test(sort_small_4, args_18)
{
	assert_sort_small("3 4 2 1", "1 2 3 4");
}
          

Test(sort_small_4, args_19)
{
	assert_sort_small("4 1 2 3", "1 2 3 4");
}
          

Test(sort_small_4, args_20)
{
	assert_sort_small("4 1 3 2", "1 2 3 4");
}
          

Test(sort_small_4, args_21)
{
	assert_sort_small("4 2 1 3", "1 2 3 4");
}
          

Test(sort_small_4, args_22)
{
	assert_sort_small("4 2 3 1", "1 2 3 4");
}
          

Test(sort_small_4, args_23)
{
	assert_sort_small("4 3 1 2", "1 2 3 4");
}
          

Test(sort_small_4, args_24)
{
	assert_sort_small("4 3 2 1", "1 2 3 4");
}
          
