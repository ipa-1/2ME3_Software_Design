## @file DCapALst.py
#  @author Alice Ip ipa1
#  @Title Department Capacity List
#  @date 2019-02-11


# @brief List that holds departments and their capacity
class DCapALst:

    ## @brief init initializes data structure
    @staticmethod
    def init():

        DCapALst.s = []

    ## @brief add adds a department to the data structure
    #  @param d department name
    #  @param n current capacity of department
    @staticmethod
    def add(d, n):

        for department in DCapALst.s:
            if department[0] == d:
                raise KeyError

        DCapALst.s.append((d, n))

    ## @brief remove removes a department from data structure
    #  @param d department name
    @staticmethod
    def remove(d):

        found = False
        for x in range(0, len(DCapALst.s)):
            if DCapALst.s[x][0] == d:
                del DCapALst.s[x]
                found = True
        if (found is False):
            raise KeyError

    ## @brief elm checks to see if deparment is in list
    #  @param d department name
    #  @return true if department is in list, false otherwise
    @staticmethod
    def elm(d):

        for department in DCapALst.s:
            if department[0] == d:
                return True
        return False

    ## @brief capacity outputs the capacity of a department
    #  @param d department name
    #  @return department's capacity
    @staticmethod
    def capacity(d):

        found = False
        for department in DCapALst.s:
            if department[0] == d:
                found = True
                return department[1]
        if (found is False):
            raise KeyError
