from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *

alice1 = SInfoT("first", "last", GenT.male, 5.0,
                ([DeptT.civil, DeptT.chemical]), True)
alice2 = SInfoT("first", "last", GenT.male, 13.0,
                ([DeptT.civil, DeptT.chemical]), True)
alice3 = SInfoT("first", "last", GenT.male, 7.0,
                ([DeptT.civil, DeptT.chemical]), True)
SALst.init()
SALst.add("ipa1", alice1)
SALst.add("ipa2", alice2)
SALst.add("ipa3", alice3)
id_list = SALst.sort(lambda t: t.freechoice and t.gpa >= 4.0)
assert(id_list == ['ipa2', 'ipa3', 'ipa1'])