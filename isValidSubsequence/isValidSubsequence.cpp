bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // iterate through the sequence
	// for each member of the sequence, iterate through the array to find it
	int i=0, j=0;
	int array_size = array.size();
	int sequence_size = sequence.size();
	for (i = 0; i < sequence_size; i++) {
		while ((array[j] != sequence[i]) && (j < array_size)) {
			j++;
		}
		if (array[j] != sequence[i]) return false;
		j++;
	}
  return true;
}
