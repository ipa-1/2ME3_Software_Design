# @file test_All.py
#  @author Alice Ip ipa1
#  @brief
#  @date 2019-02-11

import pytest
from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *
from Read import *


class TestStdntAllocTypes:

    def test_sinfot(self):
        sinfo1 = SInfoT("first", "last", GenT.male, 12.0,
                        SeqADT([DeptT.civil, DeptT.chemical]), True)
        assert (sinfo1.fname == "first")


class TestRead:

    def test_dept_data(self):
        load_dcap_data("src/DeptCap.txt")
        assert(DCapALst.elm(DeptT.civil) == True)
        assert(DCapALst.capacity(DeptT.civil) == 100)
        assert(DCapALst.elm(DeptT.chemical) == True)
        assert(DCapALst.capacity(DeptT.chemical) == 100)
        assert(DCapALst.elm(DeptT.electrical) == True)
        assert(DCapALst.capacity(DeptT.electrical) == 100)
        assert(DCapALst.elm(DeptT.mechanical) == True)
        assert(DCapALst.capacity(DeptT.mechanical) == 100)
        assert(DCapALst.elm(DeptT.software) == True)
        assert(DCapALst.capacity(DeptT.software) == 100)
        assert(DCapALst.elm(DeptT.materials) == True)
        assert(DCapALst.capacity(DeptT.materials) == 100)
        assert(DCapALst.elm(DeptT.engphys) == True)
        assert(DCapALst.capacity(DeptT.engphys) == 100)

    def test_stdnt_data(self):
        load_stdnt_data("src/StdntData.txt")
        assert(SALst.s[0][0] == "macid1")
        assert(SALst.s[0][1] == SInfoT(fname='firstname',
                                       lname='lastname', gender='male', gpa='9.2',
                                       choices=[DeptT.software, DeptT.chemical,
                                                DeptT.materials],
                                       freechoice='True'))


class TestSeqADT:

    def test_next(self):
        choices = SeqADT([DeptT.civil, DeptT.chemical])
        assert(choices.next() == DeptT.civil)
        assert(choices.next() == DeptT.chemical)
        with pytest.raises(StopIteration):
            choices.next()

    def test_start(self):
        choices = SeqADT([DeptT.civil, DeptT.chemical])
        choices.start()
        assert(choices.next() == DeptT.civil)

    def test_end_true(self):
        choices = SeqADT([])
        assert(choices.end() == True)

    def test_end_false(self):
        choices = SeqADT([DeptT.software, DeptT.chemical])
        assert(choices.end() == False)

class TestSALst:

    def test_sort(self):
        alice1 = SInfoT("first", "last", GenT.male, 5.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        alice2 = SInfoT("first", "last", GenT.male, 13.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        alice3 = SInfoT("first", "last", GenT.male, 7.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        SALst.s = [("ipa1", alice1), ("ipa2", alice2), ("ipa3", alice3)]
        id_list = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
        assert(id_list == ['ipa2', 'ipa3', 'ipa1'])

    def test_average_zero_division(self):
        SALst.s = []
        with pytest.raises(ValueError):
            SALst.average(lambda x: x.gender == GenT.male)

    def test_average_value(self):
        alice1 = SInfoT("first", "last", GenT.male, 5.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        alice2 = SInfoT("first", "last", GenT.male, 13.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        alice3 = SInfoT("first", "last", GenT.male, 7.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        SALst.s = [("ipa1", alice1), ("ipa2", alice2), ("ipa3", alice3)]
        average_value = SALst.average(lambda x: x.gender == GenT.male)
        true_value = average_value - 8.333333333333334
        close = False
        if (true_value < 0.0005):
            close = True
        assert(close is True)

    def test_allocate(self):
        DCapALst.init()
        DCapALst.add(DeptT.civil, 2)

        sinfo1 = SInfoT("first", "last", GenT.male, 12.0,
                        SeqADT([DeptT.civil, DeptT.chemical]), True)

        SALst.init()
        SALst.add("stdnt1", sinfo1)

        AALst.init()
        SALst.allocate()
        assert(AALst.s == {DeptT.civil: ['stdnt1']})

    def test_info_none(self):
        SALst.s = []
        with pytest.raises(KeyError):
            SALst.info('ipa1')

    def test_info_present(self):
        alice1 = SInfoT("first", "last", GenT.male, 5.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        alice2 = SInfoT("first", "last", GenT.male, 13.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        alice3 = SInfoT("first", "last", GenT.male, 7.0,
                        ([DeptT.civil, DeptT.chemical]), True)
        SALst.s = [("ipa1", alice1), ("ipa2", alice2), ("ipa3", alice3)]
        info_present = SALst.info('ipa1')
        assert(info_present == SInfoT("first", "last", GenT.male,
                                      5.0, ([DeptT.civil, DeptT.chemical]), True))

