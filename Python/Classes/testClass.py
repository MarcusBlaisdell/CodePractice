'''
Practice writing classes in Python
'''

class User:
    """
    Base class User:
    Class User:
        Attributes:
            first_name
            last_name
            age
        Methods:
            birthday()
                Increments age by 1
        """
    def __init__(self, first_name="", last_name="", age=0):
    #def __init__(self, first_name, last_name, age):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def birthday(self):
        self.age += 1

### Create a class that inherits from a base class:
class Manager(User):
    """
    Class Manager is a super class of class User,
    Inherits from User,
    Adds:
        title
        report method
    """
    def __init__(self, first_name="", last_name="", age=0, title=""):
        super().__init__(first_name, last_name, age)
        '''
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        '''
        self.title = title


    def report(self):
        print("Reported")

def main():
    user1 = User("Ozzy", "Franklin", 21)
    print("Name: ", user1.first_name, user1.last_name)
    print("Age: ", str(user1.age))
    user1.birthday()
    print("Age: ", str(user1.age))

    user2 = User()
    user2.first_name = "Madelaine"
    user2.last_name = "Kahn"
    user2.age = user1.age + 12
    print("Name: ", user2.first_name, user2.last_name)
    print("Age: ", str(user2.age))
    user2.birthday()
    print("Age: ", str(user2.age))

    #help(User)
    manager1 = Manager("Frank", "Herbert", 37, "Director of Sales")
    print("Name: ", manager1.first_name, manager1.last_name)
    print("Age: ", str(manager1.age))
    manager1.birthday()
    print("Age: ", str(manager1.age))
    manager1.report()

    manager2 = Manager()
    manager2.first_name="Eliot"
    manager2.last_name="Baulm"
    manager2.age=78
    print("Name: ", manager2.first_name, manager2.last_name)
    print("Age: ", str(manager2.age))
    manager2.birthday()
    print("Age: ", str(manager2.age))
    manager2.report()

    #help(Manager)

if __name__=="__main__":
    main()
