## @file StdntAllocTypes.py
#  @author Alice Ip ipa1
#  @title Student Allocation Types
#  @date 2019-02-11

from typing import *
from SeqADT import *
from enum import Enum


# @brief An enum type for gender
class GenT(Enum):
    male = 0
    female = 1


# @brief An enum type for department names
class DeptT(Enum):
    civil = 0
    chemical = 1
    electrical = 2
    mechanical = 3
    software = 4
    materials = 5
    engphys = 6


# @brief An NamedTuple to store student information
class SInfoT(NamedTuple):
    fname: str
    lname: str
    gender: GenT
    gpa: float  # type is real
    choices: SeqADT
    freechoice: bool
