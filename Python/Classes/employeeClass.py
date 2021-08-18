class employee:
    def __init__(self, firstname, lastname, salary, phone):
        self.firstname = firstname
        self.lastname = lastname
        self.salary = salary
        self.phone = phone
        self.email = self.firstname + "." + self.lastname + "@here.com"

    def giveRaise(self, theraise):
        self.salary += theraise

    def updatePhone(self, newNum):
        self.phone = newNum

class developer(employee):
    def __init__(self, firstname, lastname, salary, phone, programming_languages):
        super().__init__(firstname, lastname, salary, phone)
        self.prog_langs = programming_languages

    def addLang(self, lang):
        self.prog_langs += [lang]

employee1 = employee("Jon", "Smith", 80000, "111-222-3333")
dev1 = developer("Jane", "Greer", 100000, "123-456-7890", ["Python", "C"])

print(employee1.salary)
employee1.giveRaise(20000)
print(employee1.salary)

print(dev1.salary)
dev1.giveRaise(20000)
print(dev1.salary)

print(dev1.prog_langs)
dev1.addLang("Java")
print(dev1.prog_langs)

print(employee1.phone)
employee1.updatePhone("555-555-1234")
print(employee1.phone)
