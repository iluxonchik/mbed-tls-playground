import sys

in_file_name = sys.argv[1]

res = ''
with open(in_file_name, 'r') as luis_is_gay:
    for line in luis_is_gay:
        line = line.replace('"', '')
        line = line.replace('\\r\\n  \\\n', '')
        line = line.replace('                                       \\', '')
        line = line.replace('\\r\\n', '')
        line += '\n'
        res += line
   

print(res)
