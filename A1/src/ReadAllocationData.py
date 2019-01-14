## @file ReadAllocationData.py
#  @author Alice Ip 
#  @brief 
#  @date 2019-01-13

## @brief Formats a file input into a list of dictionaries
#  @param s string corresponding to a filename
#  @return list of dictionaries
def readStdnts(s):
	file = open(s, "r")
	allRecords = []
	sRecord = {}

	for line in file:
		sLine = line.strip()
		sLine = sLine.split(" ")

		sLineLen= len(sLine)
		while (sLineLen < 8):
			sLine.append("")
			sLineLen+=1


		sRecord = dict(macid=sLine[0], fname=sLine[1], lname=sLine[2], gender=sLine[3], gpa=sLine[4], choies=[sLine[5],sLine[6],sLine[7]])
		allRecords.append(sRecord);
	return allRecords

## @brief Formats a file input into a list of macids of students who get free choice
#  @param s string corresponding to a filename
#  @return list of macIds
def readFreeChoice(s):
	freeList=[]
	file = open(s, "r")
	for line in file:
		sLine = line.strip()
		sLine = sLine.split(" ")
		freeList.append(sLine[0])
	return freeList
