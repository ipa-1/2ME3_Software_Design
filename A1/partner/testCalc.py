## @file testCalc.py
#  @author Alice Ip 
#  @brief Test file to test functions in CalcModule
#  @date 2019-01-18

from ReadAllocationData import * 
from CalcModule import *

ave_test_1= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': 7, 'choices': ['materials', 'engphys', 'civil']},
{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': 8, 'choices': ['materials', 'software', '']},
{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': 12, 'choices': ['civil', 'chemical', 'electrical']},
{'macid': 'ipa3', 'fname': 'Alex', 'lname': 'Ip', 'gender': 'female', 'gpa': 5, 'choices': ['materials', 'chemical', 'software']}]

ave_test_2= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'male', 'gpa': 7, 'choices': ['materials', 'engphys', 'civil']},
{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': 8, 'choices': ['materials', 'software', '']},
{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': 12, 'choices': ['civil', 'chemical', 'electrical']},
{'macid': 'ipa3', 'fname': 'Alex', 'lname': 'Ip', 'gender': 'male', 'gpa': 5, 'choices': ['materials', 'chemical', 'software']}]

ave_test_3= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': 7, 'choices': ['materials', 'engphys', 'civil']},
{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': 8, 'choices': ['materials', 'software', '']},
{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': 12, 'choices': ['civil', 'chemical', 'electrical']},
{'macid': 'ipa3', 'fname': 'Alex', 'lname': 'Ip', 'gender': 'male', 'gpa': 5, 'choices': ['materials', 'chemical', 'software']}]

sort_test_1= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': 7, 'choices': ['materials', 'engphys', 'civil']},
 {'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': 8, 'choices': ['materials', 'software', '']},
  {'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': 12, 'choices': ['civil', 'chemical', 'electrical']}]

sort_test_2= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': 7, 'choices': ['materials', 'engphys', 'civil']},
 {'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': 8, 'choices': ['materials', 'software', '']},
  {'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': 7, 'choices': ['civil', 'chemical', 'electrical']}]

def assertionEqual(fname, test, result, name):
  if test == result:
    print("Test passed, %s : %s == %s, %s " % (fname, test, result, name))
  else:
    print("Test failed, %s : %s != %s, %s " % (fname, test, result, name))

def assertionApproximatelyEqual(fname, test, result, error, name):
  if abs(test - result) < error:
    print("Test passed, %s : Actual: %s  Approximate: %s, %s " % (fname, test, result, name))
  else:
    print("Test failed, %s : Actual: %s  Approximate: %s, %s " % (fname, test, result, name))		

def test_sort_1():
	test_list = sort(sort_test_1)
	list_sorted = True
	for student in range(len(test_list)-1,0,-1):
		if int(test_list[student]['gpa']) > int(test_list[student-1]['gpa']):
			list_sorted = False
			break
	assertionEqual("sort(s)", True, list_sorted, "sorted regular list")

def test_sort_2():
	test_list = sort(sort_test_2)
	list_sorted = True
	for student in range(len(test_list)-1,0,-1):
		if int(test_list[student]['gpa']) > int(test_list[student-1]['gpa']):
			list_sorted = False
			break
	assertionEqual("sort(s)", True, list_sorted, "sorted list with two duplicate gpa values")

def test_average_1():
	test_list = ave_test_1
	assertionApproximatelyEqual("average(L, g)", 6,average(test_list,"female"), 0.000005, "integer")

def test_average_2():
	test_list = ave_test_2
	assertionApproximatelyEqual("average(L, g)", 0,average(test_list,"female"), 0.000005, "no values in list matching gender")

def test_average_3():
	test_list = ave_test_3
	assertionApproximatelyEqual("average(L, g)", 8.3333333,average(test_list,"male"), 0.000005, "floating point average test")

def test_allocate_1():
	test_file_1 = "alllist.txt"
	test_file_2 = "fclist.txt"
	test_file_3 = "deptlist.txt"

	S_test = readStdnts(test_file_1)
	F_test = readFreeChoice(test_file_2)
	C_test = readDeptCapacity(test_file_3)

	result = allocate(S_test,F_test,C_test)

	expected_dictionary = [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': 7, 'choices': ['materials', 'engphys', 'civil']},{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': 8, 'choices': ['materials', 'software', '']}]
	test_bool = expected_dictionary == result["materials"]
	expected_dictionary2 = [{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': 7, 'choices': ['civil', 'chemical', 'electrical']}] 
	test_bool2 = expected_dictionary2 == result["chemical"]

	assertionEqual("allocate(S,F,C)", True , test_bool , "free choice allocated to first choice regardless of capacity")
	assertionEqual("allocate(S,F,C)", True , test_bool2 , "regular student allocated to second choice due to capacity")
	assertionEqual("allocate(S,F,C)", [], result["electrical"] , "free choice and regular students must have a gpa of 4 to be allocated")

def test_allocate_2():
	test_file_1 = "alllist2.txt"
	test_file_2 = "fclist.txt"
	test_file_3 = "deptlist.txt"

	S_test = readStdnts(test_file_1)
	F_test = readFreeChoice(test_file_2)
	C_test = readDeptCapacity(test_file_3)

	test_2_result = {'civil':[], 'chemical':[], 'electrical':[], 'mechanical':[], 'software':[], 'materials':[], 'engphys':[]}
	test_2_actual = allocate(S_test,F_test,C_test)
	print (test_2_actual)
	result = test_2_result == test_2_actual
	assertionEqual("allocate(S,F,C)", True, result , "Empty student file allocation")


def test():
	test_average_1()
	test_average_2()
	test_average_3()
	test_sort_1()
	test_sort_2()
	test_allocate_1()
	test_allocate_2()

test()
