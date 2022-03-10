int getLenght(char name[]) {
	int count = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		count++;
	}
	return count;
}
bool has_unique_char(char phrase[], int n) {
	bool char_set[256];
	memset(char_set, false, sizeof(char_set));
	for (int i = 0; i < n; i++) {
		int char_value = (int)phrase[i];
		if (char_set[char_value]) {
			return false;
		}
		char_set[char_value] = true;
	}
	return true;
}

int main() {
	char name[20];
	cout << "Enter your string: ";
	cin >> name;
	int n = getLenght(name);
	cout << has_unique_char(name, n);
	return 0;
}
// time: O(n) where n is the size of given string and space is O(1). 
