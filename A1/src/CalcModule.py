## @file CalcModule.py
#  @author Alice Ip
#  @brief Completes various calculations on the list of students created using functions in ReadAllocationDaya.py
#  @date 2019-01-13

## @brief Sorts a list of student dictionaries based on gpa
#  @param S a list of the dictionaries of students
#  @return a list of the dictionaries of students
def sort(s):
	list_length = len(s)
	for i in range(list_length-1,0,-1):
		for j in range(0,i):
			if (int((s[j])['gpa'])) < (int((s[j+1])['gpa'])):
				temp = s[j]
				s[j] = s[j+1]
				s[j+1] = temp
	return s	

