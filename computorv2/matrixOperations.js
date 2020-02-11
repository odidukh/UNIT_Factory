module.exports = {
	matrix
};


function matrix(matrix) {
	let resultMatrix = {};
	resultMatrix.matrix = matrix.substring(1, matrix.length - 1);
	matrix = resultMatrix.matrix.split(';');
	resultMatrix.rows = matrix.length;
	resultMatrix.columns = matrix[0].split(',').length;
	if (resultMatrix.rows === 1 && resultMatrix.columns === 1) {
		return parseFloat(matrix[0].substring(2, matrix[0].length - 2));
	}
	return resultMatrix;
}