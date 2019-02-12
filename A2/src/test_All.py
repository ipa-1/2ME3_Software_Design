# @file Read.py
#  @author Alice Ip ipa1
#  @brief
#  @date 2019-02-09
from pytest import *
from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *

class TestSALst:
	def test_zero_division(self):
		SALst.init()
		with raises(ValueError):
			SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)


