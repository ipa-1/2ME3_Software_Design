## @file CalcModule.py
#  @author Alice Ip
#  @brief Completes various calculations on the list of students created using functions in ReadAllocationDaya.py
#  @date 2019-01-13

## @brief Sorts a list of student dictionaries based on gpa
#  @details Using the gpa key of the student dictionaries, the positions of students in the list will be rearranged to be in order of gpa
#  @param S a list of the dictionaries of students
#  @return a list of the dictionaries of students
def sort(s):
	list_length = len(s)
	for i in range(list_length-1,0,-1):
		for j in range(0,i):
			if ((s[j])['gpa']) < ((s[j+1])['gpa']):
				temp = s[j]
				s[j] = s[j+1]
				s[j+1] = temp
	return s	

## @brief Calculates the average gpa of a list of students
#  @details Given a list of students and their gender, the average is calculated
#  @param L a list of dictionaries created by function readStdnts(s)
#  @param g a string representing male or female
#  @return average gpa of a list of students
def average(L, g):
	stud_average = 0
	person_count = 0
	for student in L:
		if student['gender'] == g:
			stud_average  += (student['gpa'])
			person_count +=1
	if person_count ==0:
		return 0
	else:
		return (stud_average/person_count)

## @brief Allocates students into departments
#  @details Given a list of dictionaries of students, list of students with free choice, and capacity, returns dictionary of department capacities 
#  @param S a list of the dictionaries of students
#  @param F a list of students with free choice
#  @param C a dictionary of department capacities
#  @return a dictionary with departments as keys and students in the program in a list as the value

#  Assumption: Only students with a gpa higher than 4 will be allocated, students with a gpa of 4 or less will not be allocated
#  Assumption: All free choice students will be granted their first choice regardless of capacity

def allocate(S,F,C):
	allocated={'civil':[], 'chemical':[], 'electrical':[], 'mechanical':[], 'software':[], 'materials':[], 'engphys':[]}
	student_allocated = False

	allocating = S.copy()
	allocating = sort(allocating)

	#Allocate the students with free choice by finding their record in the general list, checking gpa, and capacity of desired choice
	for fc_student in F: #Iterate through all students with free choice
		for all_student in allocating: #Iterate through all students in general list
			if (all_student)['macid'] == fc_student: #If macid matches
				if (all_student['gpa']) > 4: #Check if their gpa entry is greater than 4
					student_choice = ((all_student)['choices'])[0]
					allocated[student_choice].append((all_student)['macid']) #Add student to department
					allocating.remove(all_student) #Remove student from general list to keep track of who has been allocated already

				else: #Student did not have at least a 4 gpa
					allocating.remove(all_student)
	


	#Allocate the remaining students, the list is already sorted and in order of gpa
	for rem_student in allocating:
		if  (rem_student)['gpa'] >= 4:
			for choices in (rem_student)['choices']:
				for all_dept in C:
					if all_dept == choices:
						if len((allocated[all_dept])) < (C[all_dept]):
							#print(all_dept, "is an eligible choice for", (rem_student)['macid'])
							allocated[all_dept].append((rem_student))
							student_allocated = True
							allocating.remove(rem_student)
							break	
				if student_allocated == True:
					student_allocated = False
					break						
	return(allocated)

