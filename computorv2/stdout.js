
function output(variableObject) {
	if (typeof variableObject.value === 'object' && 'matrix' in variableObject.value) {
		let matrix = variableObject.value.matrix;
		matrix = matrix.split(';');
		matrix.forEach(row => {
			console.log('[ ' + row.substring(1, row.length - 1).split(',').join(' , ') + ' ]')
		})
	} else if (typeof variableObject.value === 'object' && 'functionExpression' in variableObject.value) {
		console.log(variableObject.value.functionExpression)
	} else {
		console.log(variableObject.value);
	}
}

module.exports = output;