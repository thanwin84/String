int getLenght(char name[]) {
	int count = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		count++;
	}
	return count;
}
string reverse_a_string(char name[], int n) {
	int start = 0;
	int end = n - 1;
	while (start < end) {
		swap(name[start++], name[end--]);
	}
	return name;
}

int main() {
	char name[20];
	cout << "Enter your string: ";
	cin >> name;
	int n = getLenght(name);
	cout << "reversed string is: " << reverse_a_string(name, n) << endl;
	return 0;
}
