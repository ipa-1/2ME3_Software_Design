
freeList=[]
iFile = open("alllist", "r")
for line in iFile:
	sLine = line.strip()
	sLine = sLine.split(" ")
	freeList.append(sLine[0])
