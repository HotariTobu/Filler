#include <fstream>

int main() {
	char name[10];
	int index = 0;

	char data[INT16_MAX];
	char foot[1];

	for (int i = 0; i < INT16_MAX; i++) {
		data[i] = 0;
	}
	foot[0] = 0;

	while (true) {
		sprintf_s(name, "%09d", index);

		std::ofstream os(name, std::ios::binary);
		if (os) {
			for (int i = 0; i < INT16_MAX + 2; i++) {
				os.write(data, INT16_MAX);
			}

			os.write(foot, 1);
		}
		else {
			break;
		}

		os.close();

		index++;
	}

	return 0;
}