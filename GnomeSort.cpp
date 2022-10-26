static void GnomeSort(int* data, int count) {
	for (int i = 1; i < count; ) {
		if (data[i - 1] <= data[i])
			++i;
		else {
			int tmp = data[i];
			data[i] = data[i - 1];
			data[i - 1] = tmp;
			--i;
			if (i == 0)
				i = 1;
		}
	}
}
