import java.util.Scanner;

public class pattern {

	public static boolean check(String word, String pattern, int index){
		int i;
		for (i = 0; i < word.length() - index && i < pattern.length(); i++) {
			if (word.charAt(i + index) != pattern.charAt(i)){
				return false;
			}
		}
		if (i == pattern.length()){
			return true;
		}
		else{
			return false;
		}

	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String word, pattern;
		int count = 0;
		
		System.out.println("Enter the Input");
		word = input.nextLine();

		System.out.println("Enter the pattern");
		pattern = input.nextLine();

		for (int i = 0; i < word.length(); i++) {
			if (word.charAt(i) == pattern.charAt(0)){
				if (check(word, pattern, i)){
					count++;
				}
			}
			
		}
		System.out.println(count);
		//System.out.println(check(word, pattern, 0));
	}
}