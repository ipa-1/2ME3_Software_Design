## @file AALst.py
#  @author Alice Ip ipa1
#  @brief Allocation Association List Module
#  @date 2019-02-11

from StdntAllocTypes import *


## @brief Allocation Association List that holds the students in a particular department
class AALst:

    # @brief init initial data structure
    @staticmethod
    def init():

        AALst.s = {}

    ## @brief add adds a student to a department
    #  @param dep department name
    #  @param m name of student
    @staticmethod
    def add_stdnt(dep, m):
        if (dep not in AALst.s):
            AALst.s[dep] = []
            AALst.s[dep].append(m)
        else:
            AALst.s[dep].append(m)

    ## @brief lst_alloc outputs names of students in department
    #  @param d department name
    #  @return list of students
    @staticmethod
    def lst_alloc(d):

        return AALst.s[d]

    ## @brief num_alloc outputs number of students in a department
    #  @param d department name
    #  @return number of students in a department
    @staticmethod
    def num_alloc(d):

        if (d not in AALst.s):
            return 0
            
        return len(AALst.s[d])
