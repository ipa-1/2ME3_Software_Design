from StdntAllocTypes import *
from SeqADT import *
from DCapALst import *
from AALst import *
from SALst import *

DCapALst.init()
DCapALst.add(DeptT.civil, 2)

sinfo1 = SInfoT("first", "last", GenT.male, 12.0, SeqADT([DeptT.civil, DeptT.chemical]), True)

SALst.init()
SALst.add("stdnt1", sinfo1)

AALst.init()
SALst.allocate()
print(AALst.s)
assert(AALst.s == {DeptT.civil: ['stdnt1']})
