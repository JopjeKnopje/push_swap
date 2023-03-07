from itertools import permutations


string = '''
Test(sort_small_5, args_1)
{
	assert_sort_small("{0}", "1 2 3 4");
}
'''

  
# Get all combination of [1, 2, 3]
# of length 3
comb = permutations([1, 2, 3, 4, 5], 5)
  
counter = 0
for i in comb:

    counter += 1
    args = "{0} {1} {2} {3} {4}".format(i[0], i[1], i[2], i[3], i[4])
    print('''
Test(sort_small_5, args_''' + str(counter) + ''')
{
	assert_sort_small("''' + args + '''", "1 2 3 4 5");
}
          ''')
