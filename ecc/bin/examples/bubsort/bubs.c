int main() {
	int arr[] = {7, 3, 5, 9, 1};
	int array_length = 5;
	int i = 0;
	while (i < array_length - 1) {
		int j = i + 1;
		int temp;
		while (j < array_length) {
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	
	i = 0;
	while (i < array_length) {
		print(arr[i]);
		i = i + 1;
	}
}
