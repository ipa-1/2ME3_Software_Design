## @file ReadAllocationData.py
#  @author Alice Ip 
#  @brief 
#  @date 2019-01-13

## @brief Formats a file input into a list of dictionaries
#  @param s string corresponding to a filename
#  @return list of dictionaries
def readStdnts(s):
	studentList = []
	file = open(filename, "r")
	for line in file:
		print line
