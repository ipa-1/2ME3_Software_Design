## @file SeqADT.py
#  @author Alice Ip ipa1
#  @brief An abstract data type that represents a sequence
#  @date 2019-02-11

# @brief An abstract data type that represents a sequence


class SeqADT:

    ## @brief SeqADT constructor
    #  @details takes a sequence of T
    #  @param x sequence of t
    def __init__(self, x):

        self.__s = x
        self.__i = 0

    ## @brief start resets the i value to 0
    def start(self):

        self.__i = 0

    ## @brief next increases the value of i
    #  @return the value of the previous i
    def next(self):
        self.__i += 1

        if self.__i >= len(self.__s):
            raise StopIteration

        return self.__s[self.__i - 1]

    ## @brief end determines when to end iteration
    #  @return a boolean value if i >= s
    def end(self):
        if self.__i >= len(self.__s):
            return True
        else:
            return False

