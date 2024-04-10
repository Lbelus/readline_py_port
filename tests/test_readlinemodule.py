import my_readline_module

my_readline_module.init_my_readline()
fd = open('myfile.txt', 'r')

line = None

while (line := my_readline_module.my_readline(fd.fileno())) is not None:
    print(line)

fd.close()