### Write a program that returns all indexes of values in a list
### That sum to a given target

### Use debug levels for printing,
### debug value of 1 means print information level 1, etc.
debug = 0

def findIndexes(theList, theTarget):
    myDict = {}
    newList = []

    for i in range(len(theList)):
        theGet = myDict.get(theTarget - theList[i], None)
        if theGet != None:
            if debug == 1:
                print("Indexes: ", str(i), ", ", str(theGet), " - ", str(theTarget - theList[i]), ", ", str(theList[i]))
            newList.append([i, theGet])
        else:
            myDict[theList[i]] = i

    return newList

def main():
    pass

if __name__=="__main__":
    main()
