# @file AALst.py
#  @author Alice Ip ipa1
#  @brief Allocation Association List Module
#  @date 2019-02-09

from StdntAllocTypes import *


# @brief Allocation Association List that holds the students in a particular department
class AALst:

    # @brief init initial data structure
    @staticmethod
    def __init__(self):

        self.__s = {}

    # @brief add adds a student to a department
    #  @param dep department name
    #  @param m name of student
    @staticmethod
    def add_stdnt(self, dep, m):
    	if (dep not in self.__s):
    		self.__s[dep]= []
    		self.__s[dep].append(m)
    	else:
    		self.__s[dep].append(m)


    # @brief lst_alloc outputs names of students in department
    #  @param d department name
    #  @return list of students
    @staticmethod
    def lst_alloc(self, d):

    	return self.__s[dep]

    # @brief num_alloc outputs number of students in a department
    #  @param d department name
    #  @return number of students in a department
    @staticmethod
    def num_alloc(self, d):

    	return len(self.__s[dep])


