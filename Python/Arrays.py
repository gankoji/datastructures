# Arrays are a native datatype in Python, so we don't have a whole lot to do
# here. In a different language, say C/C++, we'd want to handle things like
# allocating memory for expansion in advance (with modern strategies like
# doubling or other heuristics). Python does that for us relatively
# efficiently. 

unitTests = False

def insertInArray(el, idx, array):
    temp = array[0:idx]
    temp.append(el)
    temp = temp + array[idx:]
    return temp

def deleteFromArray(idx, array):
    temp = array[0:idx]
    temp = temp + array[idx +1:]
    return temp

def searchInArray(el, array):
    return array.index(el)

if unitTests:
    testArray = [0, 1, 2]

    print("Search test. Expected 1, got: "
          + str(searchInArray(1,testArray)))
    print("Delete test. Expected [0,2], got: "
          + str(deleteFromArray(1,testArray)))
    print("Insert test. Expected [0, 1, 7, 2], got: "
          + str(insertInArray(7, 2, testArray)))

