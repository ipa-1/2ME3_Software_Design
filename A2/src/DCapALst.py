# @file DCapALst.py
#  @author Alice Ip ipa1
#  @brief An abstract data type that stores department capacity
#  @date 2019-02-09

from StdntAllocTypes import *


# @brief An abstract data type that stores department capacity
class DCapALst:

    # @brief init initial data structure
    @staticmethod
    def __init__(self):

        self.__s = {}

    # @brief add adds a department to the data structure
    #  @param d department name
    #  @param n current capacity of department
    @staticmethod
    def add(self, d, n):

        if d in self.__s:
            raise KeyError

        self.__s[d] = n

    # @brief remove removes a department from data structure
    #  @param d department name
    @staticmethod
    def remove(self, d):

        if d not in self.__s:
            raise KeyError

        self.__s.pop(d)

    # @brief elm checks to see if deparment is in list
    #  @param d department name
    #  @return true if department is in list, false otherwise
    @staticmethod
    def elm(self, d):

        if d in self.__s:
            return True
        else:
            return False

    # @brief capacity outputs the capacity of a department
    #  @param d department name
    #  @return department's capacity
    @staticmethod
    def capacity(self, d):

        if d not in self.__s:
            raise KeyError
        return self.s[d]
