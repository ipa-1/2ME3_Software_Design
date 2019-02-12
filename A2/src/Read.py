# @file Read.py
#  @author Alice Ip ipa1
#  @brief
#  @date 2019-02-09

from DCapALst import *
from SALst import *
from StdntAllocTypes import *
from SeqADT import *

convert_dept = {'civil': DeptT.civil, 'chemical': DeptT.chemical,
                'electrical': DeptT.electrical, 'mechanical': DeptT.mechanical,
                'software': DeptT.software, 'materials': DeptT.materials,
                'engphys': DeptT.engphys}
convert_gender = {'male': GenT.male, 'female': GenT.female}


def load_stdnt_data(s):
    SALst.init()

    ifile = open(s, "r")
    for line in ifile:
        student_line = line.strip()
        student_line = student_line.split(" ")

        for x in range(0, len(student_line)):
            student_line[x] = student_line[x].replace(',', '')

        macid = student_line[0]
        first_name = student_line[1]
        last_name = student_line[2]
        gender = student_line[3].replace(',', '')
        gpa = student_line[4]
        courses = []

        for x in range(5, len(student_line) - 1):
            if (x == 5):
                student_line[5] = (student_line[5])[1::]
            if (x == (len(student_line) - 2)):
                student_line[x] = (student_line[x])[0:-1]
            courses.append(convert_dept[student_line[x]])

        freechoice = student_line[len(student_line) - 1]

        student_info = SInfoT(first_name, last_name,
                              gender, gpa, (courses), freechoice)

        SALst.add(macid, student_info)


def load_dcap_data(s):
    DCapALst.init()

    ifile = open(s, "r")
    for line in ifile:
        dept_line = line.strip()
        dept_line = dept_line.split(" ")
        capacity = int(dept_line[1])
        dept_name = dept_line[0].replace(',', '')
        dept_name = convert_dept[dept_name]
        DCapALst.add(dept_name, capacity)
