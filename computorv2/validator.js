function checkEqualSign(input) {
	if (input.replace(/[^=]/g, '').length !== 1) {
		console.log("Error: '=' sign must be single in the expression");
		return false;
	}
	return true;
}

function validator(input) {
	if (checkEqualSign(input)) {
		return true;
	}
	return false;
}

module.exports = validator;