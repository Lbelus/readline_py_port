import my_readline_module

my_readline_module.init_my_readline()

line = None

while (line := my_readline_module.my_readline(0)) is not None:
    tokens = line.split()
    print(tokens)
