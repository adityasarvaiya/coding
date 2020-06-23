import time

# # Finish this function
# def find_order(reg_number):
#     num1, first, second, num2 = int(reg_number[2:4]), reg_number[4], reg_number[5], reg_number[6:]
#     res, factor = 0, 1
#     for num in num2[::-1]:
#         res += int(num)*factor
#         factor *= 10
#     res += (ord(second) - ord('A')) * 9999
#     res += ((ord(first) - ord('A')) * 259974)
#     res += (num1 - 1)*6759324
#     return res - 1

# CRIO_SOLUTION_START_MODULE_HOT_ROAD
def to_int(ch):
    return ord(ch) - ord('A')

def find_order(reg_no):

    p4 = int(reg_no[6:])
    p3 = to_int(reg_no[4]) * 26 + to_int(reg_no[5])
    p2 = int(reg_no[2:4])
    
    return p4 + p3 * 9999 + (p2 - 1) * 9999 * 26 * 26


def find_maximum_number_of_people_accomodated(broken, good, dist):
    res = 0
    broken = sorted([list(broken) for broken in broken], key = lambda x: x[0])
    good = sorted([list(good) for good in good],  key=lambda x: x[0])
    i, j = 0, 0

    while i<len(broken) and j<len(good):
        # print(broken[i])
        # print(good[j])
        vacancy = good[j][2] - good[j][1]
        member = broken[i][1]
        good_car, broken_car = good[j][0], broken[i][0]
        if vacancy == 0:
            j += 1
            continue

        if abs(find_order(good_car)-find_order(broken_car))<=dist:
            replaced = min(vacancy, member)
            res += replaced
            vacancy -= replaced
            member -= replaced
            good[j][1] += replaced
            broken[i][1] -= replaced
            if vacancy == 0:
                j += 1
                continue
            if member == 0:
                i += 1
                continue
        else:
            i += 1
            # j += 1

    return res
