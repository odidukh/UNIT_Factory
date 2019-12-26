function sequence(expression) {
	let computationRes = 0;
	if (expression.includes('(')) {
		sequence(expression.substring(expression.indexOf('(') + 1));
	}
	
}