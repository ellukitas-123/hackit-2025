class Capicua {
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		System.out.println(siguienteCapicua(n));
	}

	static int siguienteCapicua(int n) {
		
	}

	static int cifras(int n) {
		int count = 0;

		while (n > 0) {
			count++;
			n = n / 10;
		}

		return count;
	}

	static int[] descomponer(int n) {
		int count = cifras(n);
		int[] result = new int[count];

		int i = count - 1;

		while (i >= 0) {
			result[i] = n % 10;
			n = n / 10;
			i--;
		}

		return result;
	}

	static int join(int[] arr) {
		int result = 0;

		for(int i = 0; i < arr.length; i++) {
			result += arr[i] * Math.pow(10, arr.length - 1 - i);
		}

		return result;
	}
}