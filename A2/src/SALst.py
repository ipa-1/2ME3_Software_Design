## @file SALst.py
#  @author Alice Ip ipa1
#  @brief provides services for working with the allocation and departments
#  @date 2019-02-11

from StdntAllocTypes import *
from AALst import *
from DCapALst import *
from SeqADT import *

## @brief add adds a student to a department


class SALst:

    s = []

    @staticmethod
    def init():
        SALst.s = []  # dictionary of StudentT

    ## @brief add will add macid and info into the s dictionary
    #  @param m macid of student
    #  @param i SInfoT of student

    @staticmethod
    def add(m, i):

        found = False
        for student in SALst.s:
            if student[0] == m:
                raise KeyError
        if found is False:
            SALst.s.append((m, i))

    ## @brief remove will remove m from s
    #  @param m macid of student

    @staticmethod
    def remove(m):

        found = False
        s = SALst.s
        for x in range(0, len(s)):
            student = s[x]
            if student[0] == m:
                del s[x]
                found = True
        if found is False:
            raise KeyError

    ## @brief elm checks if m is in s
    #  @param m string
    #  @return boolean indicating if m is in s

    @staticmethod
    def elm(m):

        found = False
        for student in SALst.s:
            if student[0] == m:
                return True
        if found is False:
            return False

    ## @brief info returns the student's information
    #  @param m macid of the student
    #  @return SInfoT of student

    @staticmethod
    def info(m):

        found = False
        for student in SALst.s:
            if student[0] == m:
                return student[1]
        if found is False:
            raise KeyError

    ## @brief sort sorts the s based on the filter given
    #  @param f filter to sort by
    #  @return list of macids
    @staticmethod
    def sort(f):
        filtered = []
        for student in SALst.s:
            if f(student[1]):
                filtered.append(student)

        for x in range(0, len(filtered) - 1):

            if (filtered[x][1].gpa < filtered[x + 1][1].gpa):
                temp = filtered[x]
                filtered[x] = filtered[x + 1]
                filtered[x + 1] = temp
        macid_list = []
        for y in filtered:
            macid_list.append(y[0])

        return(macid_list)

    ## @brief average calculates the average of a filtered list of students
    #  @param f filter for students to calculate average of
    #  @return a float representing average
    @staticmethod
    def average(f):

        filtered = []
        for student in SALst.s:
            if f(student[1]):
                filtered.append(student)

        if (len(filtered) == 0):
            raise ValueError

        average_sum = 0

        for x in range(0, len(filtered)):
            average_sum += filtered[x][1].gpa

        average = average_sum / (len(filtered))
        return(average)

    ## @brief allocate allocates students into deparments
    #  @details allocates freechoice students, regular students, according to gpa
    @staticmethod
    def allocate():

        AALst.init()
        freechoice_list = SALst.sort(lambda t: t.freechoice and t.gpa >= 4)

        for m in freechoice_list:
            ch = SALst.info(m).choices
            AALst.add_stdnt(ch.next(), m)

        regular_list = SALst.sort(lambda t: not t.freechoice and t.gpa >= 4)

        for m in regular_list:
            ch = SALst.info(m).choices
            alloc = False
            while (not alloc and not ch.end()):
                d = ch.next()
                if AALst.num_alloc(d) < DCapALst.capacity(d):
                    AALst.add_stdnt(d, m)
                    alloc = True

            if (not alloc):
                raise RuntimeError
                
choices = SeqADT([DeptT.civil, DeptT.chemical])
print(choices.next())