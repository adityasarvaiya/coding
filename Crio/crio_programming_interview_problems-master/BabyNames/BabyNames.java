import java.util.*;
import java.io.*;

public class BabyNames {

	static String []name = new String[200000] ;
	static  HashMap<String , ArrayList<String> > graph = new HashMap<String , ArrayList<String> > ();
	static HashMap<String , Integer > frequency = new HashMap<String, Integer>();
	static HashMap<String, Integer> visit = new HashMap<String, Integer> ();

	static Entity babyNames( String node ) {
		visit.put(node, visit.getOrDefault(node, 0) + 1);

		Entity ans = new Entity (node , frequency.get(node));

		for ( String it : graph.get(node)) {
			if (visit.containsKey(it) == true) continue;

			Entity child = babyNames(it);
			int x = child.first.compareTo(ans.first);

			if ( x < 0) {
				ans.first = child.first;
			}
			ans.second += child.second;
			ans.second = (ans.second % 1000000007);
		}
		return ans;
	}

	public static void main(String [] args) {

		Scanner sc = new Scanner(System.in);
		int noOfNames, noOfEdges;
		noOfNames = sc.nextInt();

		for ( int i = 0; i < noOfNames; i++) {
			name[i] = sc.next();
			int cnt = sc.nextInt();
			cnt %= 1000000007;
			if ( graph.containsKey(name[i]) == false) {
				graph.put(name[i], new ArrayList<String>());
			}

			frequency.put(name[i], frequency.getOrDefault(name[i], 0) + cnt);
		}
		noOfEdges = sc.nextInt();

		for ( int i = 0; i < noOfEdges; i++) {
			String u = new String();
			String v = new String();
			u = sc.next();
			v = sc.next();
			frequency.put(u, frequency.getOrDefault(u , 0));
			frequency.put(v, frequency.getOrDefault(v, 0));
			if ( graph.containsKey(u) == false) {
				graph.put(u, new ArrayList<String>());
			}
			if ( graph.containsKey(v) == false) {
				graph.put(v, new ArrayList<String>());
			}
			graph.get(u).add(v);
			graph.get(v).add(u);

		}

		ArrayList<Entity> answer = new ArrayList<Entity>();
		for ( int i = 0; i < noOfNames; i++) {

			if (visit.containsKey(name[i]) == false) {
				Entity result = babyNames(name[i]);
				answer.add(result);
			}
		}
		Collections.sort(answer , comp);
		int n = answer.size();

		for ( int i = 0; i < n; i++) {
			System.out.println(answer.get(i).first + " " + answer.get(i).second);
		}
	}

	static class Entity {

		String first;
		int second;
		Entity(String p, int q) {
			first = p;
			second = q;
		}

	}
	static Comparator<Entity> comp = new Comparator<Entity>() {
		public int compare(Entity A, Entity B) {
			int x = A.first.compareTo(B.first);
			return x;
		}
	};
}