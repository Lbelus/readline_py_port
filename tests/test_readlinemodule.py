import my_readline_module

fd = open('myfile.txt', 'r')
line = my_readline_module.my_readline(fd.fileno())
print(line)
fd.close()