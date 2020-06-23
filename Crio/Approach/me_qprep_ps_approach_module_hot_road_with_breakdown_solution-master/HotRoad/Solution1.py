# CRIO_SOLUTION_START_MODULE_HOT_ROAD
def to_int(ch):
    return ord(ch) - ord('A')

def reg_number_to_integer(reg_no):
    
    p4 = int(reg_no[6:])
    p3 = to_int(reg_no[4]) * 26 + to_int(reg_no[5])
    p2 = int(reg_no[2:4])
    
    return p4 + p3 * 9999 + (p2 - 1) * 9999 * 26 * 26

def seats_left(good_car):
    return good_car[2] - good_car[1]

def distance(car1, car2):
    return car1[0] - car2[0]

def in_range(car1, car2, dist):
    return abs(distance(car1, car2)) <= dist

# CRIO_SOLUTION_END_MODULE_HOT_ROAD

# Finish this function

def find_maximum_number_of_people_accomodated(broken, good, dist):
# CRIO_SOLUTION_START_MODULE_HOT_ROAD
    broken = [(reg_number_to_integer(x[0]), x[1]) for x in broken]
    good = [(reg_number_to_integer(x[0]), x[1], x[2]) for x in good]
    broken_cars = sorted(broken, key = lambda x : x[0])
    good_cars = sorted(good, key = lambda x : x[0])
    num_broken_cars = len(broken_cars)
    num_good_cars = len(good_cars)
  
    good_ptr = 0
    broken_ptr = 0
    result = 0

    while good_ptr < num_good_cars and broken_ptr < num_broken_cars:
        one_good_car = good_cars[good_ptr]
        one_broken_car = broken_cars[broken_ptr]
        num_seats_left = seats_left(one_good_car)
        
        if not in_range(one_good_car, one_broken_car, dist):
            if one_good_car[0] > one_broken_car[0]:
                broken_ptr += 1
            else:
                good_ptr += 1
        else:
            accomodated = min(num_seats_left, one_broken_car[1])
            good_cars[good_ptr] = (one_good_car[0], one_good_car[1] + accomodated, one_good_car[2])
            broken_cars[broken_ptr] = (one_broken_car[0], one_broken_car[1] - accomodated)
            if seats_left(good_cars[good_ptr]) == 0:
                good_ptr += 1
    
            if broken_cars[broken_ptr][1] == 0:
                broken_ptr += 1
                
            result += accomodated
    return result
# CRIO_SOLUTION_END_MODULE_HOT_ROAD
