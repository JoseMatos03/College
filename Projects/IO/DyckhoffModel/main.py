class Variable:
    def __init__(self, coefficient, name, cut_range):
        # coefficient: int
        # name: str
        # cut_range: (int, int)
        self.coefficient = coefficient
        self.name = name
        self.cut_range = cut_range

    def __eq__(self, __value: object) -> bool:
        if not isinstance(__value, Variable):
            return False
        return self.name == __value.name and self.cut_range == __value.cut_range

    def __str__(self):
        return f"{self.coefficient}{self.name}{self.cut_range[0]}{self.cut_range[1]}"


def add(var1, var2):
    if var1.name != var2.name:
        raise ValueError("Variables are not the same")
    if var1.cut_range != var2.cut_range:
        raise ValueError("Cut ranges are not the same")
    return Variable(var1.coefficient + var2.coefficient, var1.name, var1.cut_range)


def objective_function(S, D, R):
    min = []

    for l in S:
        C = get_C(l, D)
        B = get_B(l, S, D, R)

        for k in C:
            min.append(Variable(S[l], "x", (l, k)))
        for k in B:
            min.append(Variable(-S[l], "x", (k + l, k)))

    return min

def reduce_min(min):
    t_remove = []
    for (i, var) in enumerate(min):
        for (j, var2) in enumerate(min[i+1:]):
            if (j in t_remove) or (i in t_remove):
                continue
            if var == var2:
                min[i] = add(var, var2)
                t_remove.append(j)
                break

    for i in t_remove[::-1]:
        min.pop(i)

def get_constraint(l, S, D, R):
    constraint = []

    # Left side of the inequation
    A = get_A(l, S, D, R)
    B = get_B(l, S, D, R)
    for k in A:
        constraint.append(Variable(1, "x", (k, l)))
    for k in B:
         constraint.append(Variable(1, "x", (k + l, l)))

    # Right side of the inequation
    C = get_C(l, D)
    for k in C:
        constraint.append(Variable(-1, "x", (l, k)))

    return constraint

def get_constraints(S, D, R):
    constraints = []
    for l in (D or R):
        if l in S:
            continue

        constraints.append(get_constraint(l, S, D, R))

    return constraints

def remove_duplicates(constraints):
    for (i, constraint) in enumerate(constraints):
        for (j, var) in enumerate(constraint):
            if var in constraint[j+1:]:
                constraint.remove(var)


# TODO NOT RIGHT
def get_R(S, D):
    R = [k for k in D if k in S]
    return R

def get_A(l, S, D, R):
    if l not in D:
        return []
    A = [k for k in S or R if k > l]
    return A

def get_B(l, S, D, R):
    B = [k for k in D if k + l in S or k + l in R]
    return B

def get_C(l, D):
    C = [k for k in D if k < l ]
    return C

def print_min(min):
    print("min: ", end="")
    for var in min[:-1]:
        print(var, end=" + ")
    print(min[-1])

def print_constraints(constraints):
    for (i, constraint) in enumerate(constraints):
        print(f"c{i}: ", end="")
        for var in constraint[:-1]:
            print(var, end=" + ")
        print(constraint[-1])

def print_model(min, constraints):
    print_min(min)
    print()
    print_constraints(constraints)

def run():
    S = {11: 11, 10: 10, 7: 7}
    D = {5: 5, 4: 9, 3: 0, 2: 13, 1: 0}
    R = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

    min = objective_function(S, D, R)
    # reduce_min(min)
    constraints = get_constraints(S, D, R)
    for _ in range(5):
        remove_duplicates(constraints)

    print_model(min, constraints)


if __name__ == "__main__":
    run()
