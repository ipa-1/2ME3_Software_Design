## @file test_All.py
#  @author Alice Ip ipa1
#  @brief
#  @date 2019-02-11

from pytest import *
from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *

class TestStdntAllocTypes:
	def test_SInfoT(self):
		sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)
		assert (sinfo1.fname == "first")
