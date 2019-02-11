# @file Read.py
#  @author Alice Ip ipa1
#  @brief
#  @date 2019-02-09

from DCapALst import *
from SALst import *
from StdntAllocTypes import *

convert_dept = {'civil': DeptT.civil, 'chemical': DeptT.chemical, 'electrical': DeptT.electrical,
                'mechanical': DeptT.mechanical, 'software': DeptT.software, 'materials': DeptT.materials, 'engphys': DeptT.engphys}
convert_gender = {'male':GenT.male, 'female':GenT.female}


def load_stdnt_data(s):
	SALst.init()

	iFile = open(s, "r")
	for line in iFile:
		student_line = line.strip()
		student_line = student_line.split(" ")
		
		for x in range(0,len(student_line)):
			student_line[x] = student_line[x].replace(',','')

		print(student_line)
		macid = student_line[0]
		first_name = student_line[1]
		last_name = student_line[2]
		gender = student_line[3].replace(',','')
		#print(gender)
		#gender = convert_gender[student_line[3]]
		gpa = student_line[4]
		courses = []

		for x in range(5, len(student_line)-1):
			if (x == 5):
				student_line[5] = (student_line[5])[1::]
			if (x == (len(student_line)-2)):
				student_line[x] = (student_line[x])[0:-1]
			courses.append(convert_dept[student_line[x]])
		freechoice = student_line[len(student_line)-1]




		print("\n")
		#print(student_line)


        # capacity = int(dept_line[1])
        # dept_Name = dept_line[0].replace(',','')
        # dept_Name = convert_dept[dept_Name]
        # DCapALst.add(dept_Name, capacity)
        # print(DCapALst.elm(dept_Name))
        #sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)


def load_dcap_data(s):
    DCapALst.init()

    iFile = open(s, "r")
    for line in iFile:
        dept_line = line.strip()
        dept_line = dept_line.split(" ")
        capacity = int(dept_line[1])
        dept_Name = dept_line[0].replace(',','')
        dept_Name = convert_dept[dept_Name]
        DCapALst.add(dept_Name, capacity)
        # print(DCapALst.elm(dept_Name))

load_stdnt_data("StdntData.txt")
# Test
# load_dcap_data("DeptCap.txt")

'''
def readStdnts(s):
    iFile = open(s, "r")
    allRecords = []
    sRecord = {}

    for line in iFile:
        sLine = line.strip()
        sLine = sLine.split(" ")

        sLineLen = len(sLine)
        while (sLineLen < 8):
            sLine.append("")
            sLineLen += 1

        sRecord = dict(macid=sLine[0], fname=sLine[1], lname=sLine[2], gender=sLine[
                       3], gpa=float(sLine[4]), choices=[sLine[5], sLine[6], sLine[7]])
        allRecords.append(sRecord)

    return allRecords

# @brief Formats a file input into a list of macids of students who get free choice
#  @param s string corresponding to a filename
#  @return list of macIds


def readFreeChoice(s):
    freeList = []
    iFile = open(s, "r")
    for line in iFile:
        sLine = line.strip()
        sLine = sLine.split(" ")
        freeList.append(sLine[0])
    return freeList

# @brief Formats a file input into a dictionary of departments and capacities
#  @param s string corresponding to a filename
#  @return dictionary of departments and capacities


def readDeptCapacity(s):
    deptList = {}
    iFile = open(s, "r")

    for line in iFile:
        sLine = line.strip()
        sLine = sLine.split(" ")
        deptList[sLine[0]] = int(sLine[1])
    return deptList
'''
