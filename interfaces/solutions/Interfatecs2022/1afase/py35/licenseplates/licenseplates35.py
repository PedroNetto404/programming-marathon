import re

while True:
    try:
        snum = ''.join(map(lambda x: chr(int(x)), input().split(' ')))
        np = re.findall(r'[A-Z][A-Z][A-Z][0-9][A-Z][0-9][0-9]',snum)
        if len(np) > 0:
            print('MERCOSUL')
        else:
            np = re.findall(r'[A-Z][A-Z][A-Z][0-9][0-9][0-9][0-9]',snum)
            if len(np) > 0:
                print('ANTIGA')
            else:
                print('ERRO')
    except EOFError:
        break
