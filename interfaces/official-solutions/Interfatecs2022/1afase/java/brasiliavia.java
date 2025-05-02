import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

// implements the quick find method
public class brasiliavia {

	private static int numGroups;
	private static int numUnsafeGroups;
	private static int[] people;
	private static boolean needToSortAgain = true;
	private static List<Integer> unsafePeople = new ArrayList<>();

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] parts = in.readLine().split(" ");
		int howManyPeople = Integer.valueOf(parts[0]);
		int howManyEvents = Integer.valueOf(parts[1]);

		numGroups = howManyPeople;
		people = new int[howManyPeople];
		for (int i = 0; i < people.length; i++) {
			people[i] = i + 1;
		}

		StringBuilder result = new StringBuilder();
		for (int i = 0; i < howManyEvents; i++) {

			parts = in.readLine().split(" ");
			if (parts[0].equals("c")) {
				registerContact(Integer.valueOf(parts[1]) - 1, Integer.valueOf(parts[2]) - 1);
			} else if (parts[0].equals("p")) {
				registerCovid(Integer.valueOf(parts[1]) - 1);
			} else if (parts[0].equals("n")) {
				appendNumGroups(result);
			} else if (parts[0].equals("ns")) {
				appendNumSafeGroups(result);
			} else if (parts[0].equals("ni")) {
				appendNumUnsafeGroups(result);
			} else if (parts[0].equals("ii")) {
				appendUnsafePeople(result);
			}

		}

		System.out.println(result.toString());

	}

	private static void registerContact(int pa, int pb) {
		int paGroup = people[pa];
		int pbGroup = people[pb];
		if (paGroup != pbGroup)
			numGroups--;
		boolean addB2UnsafeGroup = paGroup < 0 && pbGroup > 0;
		boolean addA2UnsafeGroup = paGroup > 0 && pbGroup < 0;
		for (int i = 0; i < people.length; i++)
			if (people[i] == pbGroup) {
				people[i] = paGroup;
				if (addB2UnsafeGroup)
					unsafePeople.add(i + 1);
			} else if (people[i] == paGroup && addA2UnsafeGroup)
				unsafePeople.add(i + 1);
	}

	private static void registerCovid(int p) {
		int pGroup = people[p];
		boolean newExposed = false;
		if (pGroup > 0) {
			pGroup *= -1;
			numUnsafeGroups++;
			newExposed = true;
			needToSortAgain = true;
		}
		int absPGroup = Math.abs(pGroup);
		for (int i = 0; i < people.length; i++)
			if (Math.abs(people[i]) == absPGroup) {
				people[i] = pGroup;
				if (newExposed)
					unsafePeople.add(i + 1);
			}
	}

	public static void appendNumGroups(StringBuilder result) {
		result.append(numGroups);
		result.append(System.getProperty("line.separator"));
	}

	public static void appendNumSafeGroups(StringBuilder result) {
		result.append(numGroups - numUnsafeGroups);
		result.append(System.getProperty("line.separator"));
	}

	public static void appendNumUnsafeGroups(StringBuilder result) {
		result.append(numUnsafeGroups);
		result.append(System.getProperty("line.separator"));
	}

	public static void appendUnsafePeople(StringBuilder result) {
		if (unsafePeople.isEmpty()) {
			result.append("vazio");
			result.append(System.getProperty("line.separator"));
			return;
		}
		if (needToSortAgain) {
			Collections.sort(unsafePeople);
		}
		needToSortAgain = false;
		result.append(unsafePeople.stream().map(String::valueOf).collect(Collectors.joining(" ")));
		result.append(System.getProperty("line.separator"));
	}

}
