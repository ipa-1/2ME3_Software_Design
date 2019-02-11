# @file SALst.py
#  @author Alice Ip ipa1
#  @brief provides services for working with the allocation and departments
#  @date 2019-02-09

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

# @brief add adds a student to a department
class SALst:

	s = []

	@staticmethod
	def init(self):
	    self.__s = []  # dictionary of StudentT

	# @brief add will add macid and info into the s dictionary
	# @param m macid of student
	# @param i SInfoT of student

	@staticmethod
	def add(self,m, i):

		found = False
		for student in s:
			if student[0] == m:
				raise KeyError
		if found == False:
			s.append((m, i))

	# @brief remove will remove m from s
	# @param m macid of student

	@staticmethod
	def remove(self,m):

		found = False
		for x in range(0, len(s)):
			student = s[x]
			if student[0] == m:
				del s[x]
				found = True
		if found == False:
			raise KeyError

	# @brief elm checks if m is in s
	# @param m string
	# @return boolean indicating if m is in s

	@staticmethod
	def elm(self,m):

		found = False
		for student in s:
			if student[0] == m:
				return True
		if found == False:
			return False

	# @brief info returns the student's information
	# @param m macid of the student
	# @return SInfoT of student

	@staticmethod
	def info(self,m):

		found = False
		for student in s:
			if student[0] == m:
				return True
		if found == False:
			raise KeyError

	# @brief sort sorts the s based on the filter given
	# @param f filter to sort by
	# @return
	@staticmethod
	def sort(self,f):
		filtered = []
		for student in s:
			if f(student.info):
				filtered.append(student)



	# @brief average calculates the average of a filtered list of students
	# @param f filter for students to calculate average of
	# @return a float representing average
	@staticmethod
	def average(self,f):

		filtered = []
		for student in s:
			if f(student.info):
				filtered.append(student)

		if (len(filtered) == 0):
			raise ValueError
		return 5

	# @
	@staticmethod
	def allocate(self):
	    AALst.init()
	    F = sort(lambda t: t.freechoice and t.gpa >= 4)

	    for m in F:
	        ch = SALst.info(m).choices
	        AALst.add_stdent(ch.next(), m)





