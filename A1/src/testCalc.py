## @file testCalc.py
#  @author Alice Ip 
#  @brief 
#  @date 2019-01-15 

from ReadAllocationData import * 
from CalcModule import *

ave_test_1= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': '7', 'choices': ['materials', 'engphys', 'civil']},
{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': '8', 'choices': ['materials', 'software', '']},
{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': '12', 'choices': ['civil', 'chemical', 'electrical']},
{'macid': 'ipa3', 'fname': 'Alex', 'lname': 'Ip', 'gender': 'female', 'gpa': '5', 'choices': ['materials', 'chemical', 'software']}]

ave_test_2= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'male', 'gpa': '7', 'choices': ['materials', 'engphys', 'civil']},
{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': '8', 'choices': ['materials', 'software', '']},
{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': '12', 'choices': ['civil', 'chemical', 'electrical']},
{'macid': 'ipa3', 'fname': 'Alex', 'lname': 'Ip', 'gender': 'male', 'gpa': '5', 'choices': ['materials', 'chemical', 'software']}]

ave_test_3= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': '7', 'choices': ['materials', 'engphys', 'civil']},
{'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': '8', 'choices': ['materials', 'software', '']},
{'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': '12', 'choices': ['civil', 'chemical', 'electrical']},
{'macid': 'ipa3', 'fname': 'Alex', 'lname': 'Ip', 'gender': 'male', 'gpa': '5', 'choices': ['materials', 'chemical', 'software']}]

sort_test_1= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': '7', 'choices': ['materials', 'engphys', 'civil']},
 {'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': '8', 'choices': ['materials', 'software', '']},
  {'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': '12', 'choices': ['civil', 'chemical', 'electrical']}]

sort_test_2= [{'macid': 'ipa1', 'fname': 'Alice', 'lname': 'Ip', 'gender': 'female', 'gpa': '7', 'choices': ['materials', 'engphys', 'civil']},
 {'macid': 'ipk2', 'fname': 'Kevin', 'lname': 'Ip', 'gender': 'male', 'gpa': '8', 'choices': ['materials', 'software', '']},
  {'macid': 'ipe3', 'fname': 'Eric', 'lname': 'Ip', 'gender': 'male', 'gpa': '7', 'choices': ['civil', 'chemical', 'electrical']}]

def assertionEqual(test, result, name):
  if test == result:
    print("Test passed, %s == %s, %s " % (test, result, name))
  else:
    print("Test failed, %s != %s, %s " % (test, result, name))

def assertionApproximatelyEqual(test, result, error, name):
  if abs(test - result) < error:
    print("Test passed, Actual: %s  Approximate: %s, %s " % (test, result, name))
  else:
    print("Test failed, Actual: %s  Approximate: %s, %s " % (test, result, name))		

def test_sort_1():
	test_list = sort(sort_test_1)
	list_sorted = True
	for student in range(len(test_list)-1,0,-1):
		if int(test_list[student]['gpa']) > int(test_list[student-1]['gpa']):
			list_sorted = False
			break
	assertionEqual(True, list_sorted, "sorted")

def test_sort_2():
	test_list = sort(sort_test_2)
	list_sorted = True
	for student in range(len(test_list)-1,0,-1):
		if int(test_list[student]['gpa']) > int(test_list[student-1]['gpa']):
			list_sorted = False
			break
	assertionEqual(True, list_sorted, "sorted")

def test_average_1():
	test_list = ave_test_1
	assertionApproximatelyEqual(6,average(test_list,"female"), 0.000005, "average1: integer")

def test_average_2():
	test_list = ave_test_2
	assertionApproximatelyEqual(0,average(test_list,"female"), 0.000005, "average2: no values in list matching gender")

def test_average_3():
	test_list = ave_test_3
	assertionApproximatelyEqual(8.3333333,average(test_list,"male"), 0.000005, "average3: floating point average test")

def test_allocate_1():
	test_file_1 = "alllist.txt"
	test_file_2 = "fclist.txt"
	test_file_3 = "deptlist.txt"
	result = allocate("alllist.txt","fclist.txt","deptlist.txt")
	assertionEqual(['ipa1'], result["materials"] , "sorted")

def test():
	test_average_1()
	test_average_2()
	test_average_3()
	test_sort_1()
	test_sort_2()
	test_allocate_1()

test()