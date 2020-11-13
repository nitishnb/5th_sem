def print_grid(src):  # print the grid
    state = src.copy()
    state[state.index(-1)] = ' '
    print(f"""            {state[0]} {state[1]} {state[2]}
            {state[3]} {state[4]} {state[5]}
            {state[6]} {state[7]} {state[8]}""")


def h(state, target):
    dist = 0
    for i in state:
        d1, d2 = state.index(i), target.index(i)
        x1, y1 = d1 % 3, d1 // 3
        x2, y2 = d2 % 3, d2 // 3
        dist += abs(x1-x2) + abs(y1-y2) # Manhattan distance
    return dist


def astar(src, target, depth):  # a* algorithm
    states = [src]
    g = 0
    visited_states = set()
    while len(states) and g <= depth:
        print(f"Level: {g}")
        moves = []
        for state in states:
            visited_states.add(tuple(state))
            print_grid(state)
            if state == target:
                print("Success")
                return

            # all possible moves of the state are stored in the list moves

            moves = [move for move in possible_moves(
                state, visited_states) if move not in moves]
            # print(moves)

        # for each move in moves cost of the particular move is stored
        costs = [g + h(move, target) for move in moves]
        # print(costs)     f(n) = g(n) + h(n)
        states = [moves[i]
                  for i in range(len(moves)) if costs[i] == min(costs)]
        # print(states)    min cost
        g += 1
    print("NO SOLUTION")
    print("The goal state is not reached within the limit : ", depth)



def possible_moves(state, visited_states):
    b = state.index(-1)
    d = []
    if b >= 3:
        d += 'u'
    if b < 6:
        d += 'd'
    if (b+1) % 3 != 0:
        d += 'r'
    if b % 3 != 0:
        d += 'l'
    pos_moves = []
    for move in d:
        pos_moves.append(gen(state, move, b))
    return [move for move in pos_moves if tuple(move) not in visited_states]


def gen(state, dir, b):
    temp = state.copy()
    if dir == 'u':
        temp[b-3], temp[b] = temp[b], temp[b-3]
    elif dir == 'd':
        temp[b+3], temp[b] = temp[b], temp[b+3]
    elif dir == 'r':
        temp[b+1], temp[b] = temp[b], temp[b+1]
    else:
        temp[b-1], temp[b] = temp[b], temp[b-1]
    return temp



src = [8, 2, 3,
      -1, 4, 6,
       7, 5, 1]
target = [1, 2, 3,
          4, 5, 6,
          7, 8, -1]
depth = 3

astar(src, target, depth)
