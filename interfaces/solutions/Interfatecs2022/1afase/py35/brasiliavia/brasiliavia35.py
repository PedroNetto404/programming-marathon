num_people, num_events = map(int, input().split(' '))

num_groups = num_people
num_usf_groups = 0
usf_people = []
people = list(range(num_people))

def set_contact(pa, pb):
    global num_groups, num_usf_groups, usf_people, people
    pag, pbg = people[pa], people[pb]

    if pag == pbg:
        return

    if pag < 0 and pbg < 0:
        num_usf_groups -= 1

    add_b_2_usf = pag < 0 and pbg > 0
    add_a_2_usf = pag > 0 and pbg < 0

    new_grp = min(pag, pbg)

    for i, pp in enumerate(people):
        if pp == pbg:
            people[i] = new_grp
            if add_b_2_usf:
                usf_people.append(i+1)
        elif pp == pag:
            people[i] = new_grp
            if add_a_2_usf:
                usf_people.append(i+1)
    
    num_groups -= 1

def set_covid(p):
    global num_groups, num_usf_groups, usf_people, people
    pgrp = people[p]
    
    if pgrp < 0:
        return

    new_grp = -pgrp
    num_usf_groups += 1
    
    for i, pp in enumerate(people):
        if pp == pgrp:
            people[i] = new_grp
            usf_people.append(i+1)


for i in range(num_events):
    pts = input().split(' ')

    if pts[0] == 'c':
        set_contact(int(pts[1])-1, int(pts[2])-1) 
    elif pts[0] == 'p':
        set_covid(int(pts[1])-1) 
    elif pts[0] == 'n':
        print(num_groups)
    elif pts[0] == 'ns':
        print(num_groups-num_usf_groups)
    elif pts[0] == 'ni':
        print(num_usf_groups)
    elif pts[0] == 'ii':
        if not usf_people:
            print('vazio')
        else:
            usf_people.sort()
            print(' '.join(map(str, usf_people)))


