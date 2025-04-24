import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

// implements the quick find method
public class geradorBrasiliaviaOut {

	private static int numGroups;
	private static int numUnsafeGroups;
	private static int[] people;
	private static List<Integer> unsafePeople = new ArrayList<>();

	public static void main(String[] args) {

		String[] parts = null;
		for (int m = 1; m <= 10; m++) {
			try {
				BufferedReader in = new BufferedReader(new FileReader("brasiliavia" + m + ".in"));
				BufferedWriter out = new BufferedWriter(new FileWriter("brasiliavia" + m + ".out"));

				parts = in.readLine().split(" ");
				int howManyPeople = Integer.valueOf(parts[0]);
				int howManyEvents = Integer.valueOf(parts[1]);

				numGroups = howManyPeople;
				numUnsafeGroups = 0;
				people = new int[howManyPeople];
				for (int i = 0; i < people.length; i++) {
					people[i] = i + 1;
				}
				unsafePeople.clear();

				StringBuilder result = new StringBuilder();
				for (int i = 0; i < howManyEvents; i++) {

					parts = in.readLine().split(" ");
					if (parts[0].equals("c")) {
						registerContact(Integer.valueOf(parts[1]) - 1, Integer.valueOf(parts[2]) - 1);
					} else if (parts[0].equals("p")) {
						registerCovid(Integer.valueOf(parts[1]) - 1);
					} else if (parts[0].equals("n")) {
						appendNumGroups(i + 2, result);
					} else if (parts[0].equals("ns")) {
						appendNumSafeGroups(i + 2, result);
					} else if (parts[0].equals("ni")) {
						appendNumUnsafeGroups(i + 2, result);
					} else if (parts[0].equals("ii")) {
						appendUnsafePeople(i + 2, result);
					}

				}

				out.write(result.toString());
				out.close();
				in.close();
			} catch (Exception e) {
				e.printStackTrace();
				System.out.println(String.join(",", parts));
			}

		}

	}

	private static void registerContact(int pa, int pb) {
		int paGroup = people[pa];
		int pbGroup = people[pb];

		if (paGroup == pbGroup)
			return;

		if(paGroup < 0 && pbGroup < 0) {
			numUnsafeGroups--;
		}
		
		boolean addB2UnsafeGroup = paGroup < 0 && pbGroup > 0;
		boolean addA2UnsafeGroup = paGroup > 0 && pbGroup < 0;

		int newGroup = Math.min(paGroup, pbGroup);

//		if (pa == 490 - 1 && pb == 565 - 1) {
//			System.out.println(paGroup);
//			System.out.println(addA2UnsafeGroup);
//			System.out.println(pbGroup);
//			System.out.println(addB2UnsafeGroup);
//		}

		for (int i = 0; i < people.length; i++)
			if (people[i] == pbGroup) {
				people[i] = newGroup;
				if (addB2UnsafeGroup)
					unsafePeople.add(i + 1);
			} else if (people[i] == paGroup) {
				people[i] = newGroup;
				if (addA2UnsafeGroup)
					unsafePeople.add(i + 1);
			}

		numGroups--;
	}

	private static void registerCovid(int p) {
		int pGroup = people[p];
		if (pGroup < 0) // ja tem covid
			return;

		int newPGroup = -pGroup; // marcar como covidado
		numUnsafeGroups++;

		for (int i = 0; i < people.length; i++)
			if (people[i] == pGroup) { // todos do mesmo grupo tem covid
				people[i] = newPGroup;
				unsafePeople.add(i + 1);
//				if (i + 1 == 249) {
//					System.out.println("Adicionei 249. Grupo dele tem = " + people[i]);
//				}
			}
	}

	public static void appendNumGroups(int inputLine, StringBuilder result) {
//		result.append(inputLine);
//		result.append(" ");
		result.append(numGroups);
		result.append(System.getProperty("line.separator"));
	}

	public static void appendNumSafeGroups(int inputLine, StringBuilder result) {
//		result.append(inputLine);
//		result.append(" ");
		result.append(numGroups - numUnsafeGroups);
		result.append(System.getProperty("line.separator"));
	}

	public static void appendNumUnsafeGroups(int inputLine, StringBuilder result) {
//		result.append(inputLine);
//		result.append(" ");
		result.append(numUnsafeGroups);
		result.append(System.getProperty("line.separator"));
	}

	public static void appendUnsafePeople(int inputLine, StringBuilder result) {
//		result.append(inputLine);
//		result.append(" ");
		if (unsafePeople.isEmpty()) {
			result.append("vazio");
			result.append(System.getProperty("line.separator"));
			return;
		}
		Collections.sort(unsafePeople);
		result.append(unsafePeople.stream().map(String::valueOf).collect(Collectors.joining(" ")));
		result.append(System.getProperty("line.separator"));
	}

}
