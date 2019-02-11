# @file SALst.py
#  @author Alice Ip ipa1
#  @brief provides services for working with the allocation and departments
#  @date 2019-02-09

from StdntAllocTypes import *
from AALst import *
from DCapALst import *

# @brief add adds a student to a department


def init():
    s = []  # dictionary of StudentT

# @brief add will add macid and info into the s dictionary
# @param m macid of student
# @param i SInfoT of student

def add(m, i):

	found = False
	for x in s:
		if x[0] == m:
			raise KeyError
	if found == False:
		s.append((m,i))

# @brief remove will remove m from s
# @param m macid of student


def remove(m):

	found = False
	for x in range(0,len(s)):
		t = s[x]
		if t[0] == m:
			del s[x]
			found = True
	if found == False:
		raise KeyError

# @brief elm checks if m is in s
# @param m string
# @return boolean indicating if m is in s


def elm(m):

	if (m in s):
		return True
	else:
		return False
# @brief info returns the student's information
# @param m macid of the student
# @return SInfoT of student
def info(m):

	return s[m]

'''
# @brief sort sorts the s based on the filter given
# @param f filter to sort by
# @return
def sort(f):


def average(f):
    if len(s) == 0
        raise ValueError


def allocate():
    AALst.init()
    F = sort(lamda t: t.freechoice and t.gpa >= 4)
    for m in F:
        ch = SALst.info(m).choices
        AALst.add_stdent(ch.next(), m)
'''