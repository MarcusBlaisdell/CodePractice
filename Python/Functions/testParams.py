### test python parameters in a function

def funcOne (a):
    print("a before " + str(a))
    a += 1
    print("a after " + str(a))

def main():
    a = 2
    print("b before: " + str(a))
    funcOne(a)
    print("b after: " + str(a))

if __name__ == "__main__":
    main()
