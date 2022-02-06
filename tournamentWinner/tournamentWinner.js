function tournamentWinner(competitions, results) {
	const score = {};
	for (let i = 0; i < results.length; i++) {
		const key_1 = competitions[i][0];
		const key_2 = competitions[i][1];
		if (results[i] === 1) {
			if (score[key_1] !== undefined) {
				score[key_1] += 3;
			} else {
				score[key_1] = 3;
			}
			if (score[key_2] === undefined) {
				score[key_2] = 0;
			}
		} else {
			if (score[key_2] !== undefined) {
				score[key_2] += 3;
			} else {
				score[key_2] = 3;
			}
			if (score[key_1] === undefined) {
				score[key_1] = 0;
			}
		}
	}
	const max = Object.keys(score).reduce((a, v) => Math.max(a, score[v]), -Infinity);
	const result = Object.keys(score).filter(v => score[v] === max);
	return result[0];
}

// Do not edit the line below.
exports.tournamentWinner = tournamentWinner;

