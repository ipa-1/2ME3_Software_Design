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

class TestRead:
	def setup_method(self, method):
		stdntf = load_stdnt_data("StdntData.txt")
		deptf = load_dcap_data("DeptCap.txt")
