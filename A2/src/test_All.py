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
from Read import *

class TestStdntAllocTypes:
	def test_SInfoT(self):
		sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)
		assert (sinfo1.fname == "first")

class TestRead:
        def test_dept_data(self):
                load_dcap_data("src/DeptCap.txt")
                assert(DCapALst.s[0][0] == DeptT.civil)
                assert(DCapALst.s[0][1] == 100)
                assert(DCapALst.s[1][0] == DeptT.chemical)
                assert(DCapALst.s[1][1] == 100)
                assert(DCapALst.s[2][0] == DeptT.electrical)
                assert(DCapALst.s[2][1] == 100)
                assert(DCapALst.s[3][0] == DeptT.mechanical)
                assert(DCapALst.s[3][1] == 100)
                assert(DCapALst.s[4][0] == DeptT.software)
                assert(DCapALst.s[4][1] == 100)
                assert(DCapALst.s[5][0] == DeptT.materials)
                assert(DCapALst.s[5][1] == 100)
                assert(DCapALst.s[6][0] == DeptT.engphys)
                assert(DCapALst.s[6][1] == 100)

class TestRead:
       def test_stdnt_data(self):
          load_stdnt_data("src/StdntData.txt")
          assert(SALst.s[0][0]=="macid1" )
          assert(SALst.s[0][1]==SInfoT(fname='firstname', lname='lastname', gender='male', gpa='9.2', choices=[DeptT.software, DeptT.chemical, DeptT.materials], freechoice='True'))
