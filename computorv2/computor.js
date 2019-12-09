const parser = require('./parser');
const validator = require('./validator');
let stdin = process.openStdin();
let variables = {};

stdin.addListener("data", d => {
	let input = d.toString().trim();
	let nameAndValue = parser(input);
	if (validator(input)) {
		variables[nameAndValue.name] = nameAndValue.value;
		console.log(variables);
		console.log(nameAndValue.value);
	}
});