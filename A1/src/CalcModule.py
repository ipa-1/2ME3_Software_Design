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

## @brief Returns the average gpa of male or females students
#  @param L a list of dictionaries created by function readStdnts(s)
#  @param g a string representing male or female
def average(L, g):
	stud_average = 0
	person_count = 0
	for student in L:
		if student['gender'] == g:
			average  += int(student['gpa'])
			person_count +=1
	if person_count ==0:
		return 0
	else:
		return ((average)/person_count)
