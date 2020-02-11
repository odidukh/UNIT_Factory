const parseAndCompute = require('./parser');
const validator = require('./validator');
const output = require('./stdout');
const func = require('./functions');
let stdin = process.openStdin();
let variables = {};

stdin.addListener("data", d => {
	validator(d.toString());
	let input = d.toString().trim();
	input = input.split('=');

	Object.keys(variables).forEach(variableName => {
		while (input[1].includes(variableName) && typeof input[1] === "object" && input[1].functionName) {
			input[1] = input[1].replace(new RegExp("\\b" + variableName + "\\b", 'g'), variables[variableName]);
		}
		if (input[1].includes(variableName) && typeof input[1] !== "object") {
			input[1] = input[1].replace(new RegExp("\\b" + variableName + "\\b", 'g'), variables[variableName]);
		}
	});
	input = input.join('=');
	let variableObject = parseAndCompute(input);
	variables[variableObject.name] = variableObject.value;
	console.log(variables);
	output(variableObject);
});