## @file StdntAllocTypes.py
#  @author Alice Ip ipa1
#  @brief
#  @date 2019-02-09

from typing import *

from enum import Enum
class GenT(Enum):
	male = 0
	female = 1

class DeptT(Enum):
	civil = 0
	chemical = 1
	electrical = 2
	mechanical = 3
	software = 4
	materials = 5
	engphys = 6



class SInfoT(NamedTuple):
	fname: str
	lname: str
	gender: GenT
	gpa: int # change to R?
	#choices: SeqADT(DeptT)
	freechoice: bool