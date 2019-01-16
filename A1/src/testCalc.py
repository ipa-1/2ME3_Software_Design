## @file testCalc.py
#  @author Alice Ip 
#  @brief 
#  @date 2019-01-15 

from ReadAllocationData import * 
from CalcModule import *

file = "data.txt"
list = readStdnts(file)
list = sort(list)
for x in list:
	print(x)	
