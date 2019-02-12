# @file DCapALst.py
#  @author Alice Ip ipa1
#  @brief An abstract data type that stores department capacity
#  @date 2019-02-09

from StdntAllocTypes import *
from SeqADT import *


# @brief An abstract data type that stores department capacity
class DCapALst:

    # @brief init initial data structure
    @staticmethod
    def init():

        DCapALst.s = []

    # @brief add adds a department to the data structure
    #  @param d department name
    #  @param n current capacity of department
    @staticmethod
    def add(d, n):

        for department in DCapALst.s:
            if department[0] == d:
                raise KeyError

        DCapALst.s.append((d, n))

    # @brief remove removes a department from data structure
    #  @param d department name
    @staticmethod
    def remove(d):

        found = False
        for x in range(0, len(DCapALst.s)):
            if DCapALst.s[x] == d:
                del DCapALst.s[x]
                found = True
        if (found == False):
            raise KeyError

    # @brief elm checks to see if deparment is in list
    #  @param d department name
    #  @return true if department is in list, false otherwise
    @staticmethod
    def elm(d):

        for department in DCapALst.s:
            if department[0] == d:
                return True
        return False

    # @brief capacity outputs the capacity of a department
    #  @param d department name
    #  @return department's capacity
    @staticmethod
    def capacity(d):

        found = False
        for department in DCapALst.s:
            if department[0] == d:
                return department[1]
                found = True
        if (found == False):
            raise KeyError

#x = SeqADT([1, 2, 3])
# print(x.next())
