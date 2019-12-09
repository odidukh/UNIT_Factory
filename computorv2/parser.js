function complexNumbers(value) {

}

function matrix(value) {
	return undefined;
}

function realNumbers(value) {
	let number;

	
	return number;
}

function correctTypeParser(value) {
	switch (value) {
		case value.includes('i'):
			return complexNumbers(value);
		case value.includes('['):
			return matrix(value);
		case !value.includes(/[a-z]/):
			return realNumbers(value);
	}
}

function functionProcessor(input) {

}

function nameAndValue(input) {
	input = input.split(" ").join("").split('=');
	input[1] = input[0].includes('(') ? functionProcessor(input[1]) : correctTypeParser(input[1]);
	return {
		name: input[0],
		value: input[1]
	}
}

module.exports = nameAndValue;