import os
print('\nCreate Account : Enter ( Create ) \nTo Login : Enter ( Login ) \nTo Change Password : Enter ( Reset )\n')
data = input("How Can I Help You\n")
if data == 'create':
    def data_fun(name,password):
        path="path"+name
        isFile = os.path.isfile(path)
        if isFile is True:
            print("\nUser Name Not Available\n")
        else:
            with open("path"+name,'a') as create:
                create.write("User:"+name+" "+"Passwd:"+password)
                print("\nAccount Create Successfully\n")
    name = input("Enter Your User Name :")
    password = input("Enter User Password :")
    data_fun(name,password)
elif data == 'login':
    def data_fun(name,password):
        path="path"+name
        isFile = os.path.isfile(path)
        if isFile is True:
            with open("path"+name,'r') as login:
                user=("User:"+name+" "+"Passwd:"+password)
                if user == login.readline():
                    print("\nLogin Successfully\n")
        else:
            print("\nEntered Credentials are Invalid\n")
    name = input("Enter Your User Name :")
    password = input("Enter User Password :")
    data_fun(name,password)
elif data == 'reset':
        def data_name(name,password,newpassword):
            with open("path"+name,'r') as reset:
                user="User:"+name+" Passwd:"+password
                if user in reset.readlines():
                    content = user
                    with open("path"+name,'w+') as files:
                        lines = files.readlines()
                        for line in lines:
                            if line.strip("\n") != content:
                                files.write (line)
                    c="User:"+name+" Passwd:"+newpassword
                    with open("path"+name,'a') as reset_new:
                        reset_new.write(c)
                        print("\nPassword Changed Successfully\n")
                else:
                    print('\nPlease Enter Correct Credentials\n')
        name=input("Enter User Name : ")
        password=input("Enter User Password : ")
        newpassword=input("Enter New Password : ")
        data_name(name,password,newpassword)       
else:
    print("\nPlease Enter Correct Credentials\n")
