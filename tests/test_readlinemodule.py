import my_readline_module

my_readline_module.init_my_readline()
fd = open('myfile.txt', 'r')

line = my_readline_module.my_readline(fd.fileno())
while line != None:
    print(line)
    line = my_readline_module.my_readline(fd.fileno())
fd.close()