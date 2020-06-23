import java.lang.*;
import java.util.*;

class Solution {
    //CRIO_SOLUTION_START_MODULE_HOT_ROAD

    public static int reg_number_to_integer(String reg_no) {

	int p4 = Integer.parseInt(reg_no.substring(6));
	int p3 =  (reg_no.charAt(4) - 'A') * 26 + (reg_no.charAt(5) - 'A');
	int p2 =  Integer.parseInt(reg_no.substring(2, 4));

	return (p4 + p3 * 9999 + (p2 - 1) * 9999 * 26 * 26);
    }

    public static int seats_left(Entity2 good_car) {
	return (good_car.third - good_car.second);
    }

    public static int dis(Pair car1, Pair car2) {
	return (car1.first - car2.first);
    }

    public static boolean in_range(Pair car1, Pair car2, int k) {
	return (Math.abs(dis(car1, car2)) <= k);
    }

    //CRIO_SOLUTION_END_MODULE_HOT_ROAD


    // Finish this function

    public static int find_maximum_number_of_people_accomodated(ArrayList<Entity1> broken, ArrayList<Entity2> good , int k) {
	//CRIO_SOLUTION_START_MODULE_HOT_ROAD
	int m = good.size();
	int n = broken.size();
	ArrayList<Pair> brokenCar = new ArrayList<Pair> ( );
	ArrayList<Pair> goodCar = new ArrayList<Pair> ( );
	for ( int i = 0; i < n; i++) {
	    Pair car = new Pair(reg_number_to_integer(broken.get(i).first), broken.get(i).second);
	    brokenCar.add(car);
	}

	for ( int i = 0; i < m; i++) {

	    Pair car = new Pair(reg_number_to_integer(good.get(i).first), seats_left(good.get(i)));
	    goodCar.add(car);
	}


	Collections.sort(brokenCar , Pair.comp);
	Collections.sort(goodCar , Pair.comp);

	int brokenPtr = 0, goodPtr =  0, answer = 0;
	while (brokenPtr < n && goodPtr < m) {

	    Pair goodOne = goodCar.get(goodPtr);
	    Pair brokenOne = brokenCar.get(brokenPtr);
	    if (in_range(goodOne , brokenOne, k ) == false) {
		if (goodOne.first > brokenOne.first) {
		    brokenPtr++;
		} else {

		    goodPtr++;
		}
	    } else {
		int put = Math.min(goodOne.second, brokenOne.second);
		brokenCar.get(brokenPtr).second -= put;

		goodCar.get(goodPtr).second -= put;
		if (goodCar.get(goodPtr).second == 0) {
		    goodPtr++;
		}
		if (brokenCar.get(brokenPtr).second == 0) {
		    brokenPtr++;
		}
		answer += put;
	    }
	}
	return answer;
	//CRIO_SOLUTION_END_MODULE_HOT_ROAD
    }
}
