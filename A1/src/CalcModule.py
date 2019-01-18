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
			if (int((s[j])['gpa'])) < (int((s[j+1])['gpa'])):
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
			average  += int(student['gpa'])
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
def allocate(S,F,C):
	allocated={'civil':[], 'chemical':[], 'electrical':[], 'mechanical':[], 'software':[], 'materials':[], 'engphys':[]}
	student_allocated = False
	allocating = S.copy()
	allocating = sort(allocating)

	#Allocate the students with free choice by finding their record in the general list, checking gpa, and capacity of desired choice
	for fc_student in F: #Iterate through all students with free choice
		for all_student in allocating: #Iterate through all students in general list

			if (all_student)['macid'] == fc_student: #If macid matches
				if int((all_student)['gpa']) >= 4: #Check if their gpa entry is less than or equal to 4
					#print((all_student)['macid'], "is eligible for fc")
					for choices in (all_student)['choices']: #Iterate through the current student's choices
						for all_dept in C: #Iterate through the departments in the capacity list
							if all_dept == choices: #If the choice is found in the capacity list
								if len((allocated[all_dept])) < int(C[all_dept]): #Check to see if at full capacity
									#print(all_dept, "is an eligible choice for", (all_student)['macid'])
									allocated[all_dept].append((all_student)['macid']) #Add student to department
									student_allocated = True #Set boolean value to exit all loops
									allocating.remove(all_student) #Remove student from general list to keep track of who has been allocated already
									break
						if student_allocated == True: # If the student was allocated to one of their choices
							break
					if student_allocated == True:
						student_allocated = False
						break

					for choices in C: #If all deparments of student's choice are full, allocate to 
						if len((allocated[choices])) < int(C[choices]):
							#print(choices, "is an eligible choice for", (all_student)['macid'])
							allocated[choices].append((all_student)['macid'])
							allocating.remove(all_student)
							break
				else: #Student did not have at least a 4 gpa
					allocating.remove(all_student)

	for rem_student in allocating:
		if int ((rem_student)['gpa']) >= 4:
			for choices in (rem_student)['choices']:
				for all_dept in C:
					if all_dept == choices:
						if len((allocated[all_dept])) < int(C[all_dept]):
							#print(all_dept, "is an eligible choice for", (rem_student)['macid'])
							allocated[all_dept].append((rem_student)['macid'])
							student_allocated = True
							allocating.remove(rem_student)
							break	
				if student_allocated == True:
					student_allocated = False
					break						
	return(allocated)
