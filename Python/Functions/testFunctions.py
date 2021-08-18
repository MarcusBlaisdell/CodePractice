def f():
    print("f has run")

# def f1(x): ### No default value
def f1(x=1): ### Default value = 1
    return x + 1

# def f2(x, y=1): ### First has no default value, Second has default value
# def f2(x=0, y): ### First has default value, Second has no default value
def f2(x=0, y=1): ### Both have default values
    return x + y

def f2a(x, y): ### 2 arguments, neither have defaults
    x+=1
    y+=2
    return x,y

### test doc string
def f3():
    """f3 is an empty function that returns this statement when requested through help"""
    pass

def f4(*args):
    return len(args)

def main():
    f()
    ### Test f1 default by not passing an argument:
    print("x should be 2: ", str(f1()))
    ### Test f1 default by passing an argument:
    print("x should be 4: ", str(f1(3)))
    ### Test f2, both have defaults:
    print("z should be 1: ", str(f2()))
    ### Test f2, first has default:
    print("z should be 2: ", str(f2(x=1)))
    ### Test f2, pass 1 default only:
    print("z should be 2: ", str(f2(1)))
    ### Test f2, pass second default only:
    print("z should be 3: ", str(f2(y=3)))
    ### Test f2a:
    x, y = f2a(2,2)
    print("x should be 3: ", str(x), " y should be 4: ", str(y))
    ### Test f2, pass 2 values:
    print("z should be 11: ", str(f2(5,6)))
    ### test f3 doc string:
    #help(f3)
    ### print dir:
    dir()

if __name__ == "__main__":
    main()
