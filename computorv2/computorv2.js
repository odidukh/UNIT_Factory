const parseAndCompute = require('./parser');
const validator = require('./validator');
const realNumberComp = require('./realNumCalculation');
const output = require('./stdout');
const func = require('./functions');
const equationSolver = require('./functionComputor');

let stdin = process.openStdin();

global.variablesDB = {
	'real'	   : {},
	'functions': {},
	'matrices' : {},
	'complexes': {},
};

// global.history = 'I\nam\na\nhistory';
let history = '';
(function(){
	let oldLog = console.log;
	console.log = function (message) {
		history += Array.prototype.join.call(arguments, ' ') + '\n';
		oldLog.apply(console, arguments);
	};
})();

global.saveAndOutput = function (output) {
	history.concat('\n', output);
	console.log(output);
}

function variableToValue(variables, stringWithVariables) {
	Object.keys(variables).forEach(variableName => {
		if (stringWithVariables.includes(variableName)) {
			stringWithVariables = stringWithVariables.replace(
				new RegExp("\\b" + variableName + "\\b", 'g'),
				variables[variableName]);
		}
	});
	return stringWithVariables;
}

function generalComputations(inputString) {
	history.concat('\n', inputString.split(' ').join(''));
	let splittedInputArray = inputString.split(' ').join('').split('=');

	let leftPart = splittedInputArray[0];
	let rightPart = splittedInputArray[1];

	function getLeftPartValue(toComputeString) {
		toComputeString = variableToValue(variablesDB.real, toComputeString);
		toComputeString = func.functionRead(variablesDB.functions, toComputeString);
		let result = realNumberComp(toComputeString);
		saveAndOutput(result);
	}

	function solveEquation(leftPart, rightPart) {
		rightPart = variableToValue(variablesDB, rightPart);
		let equation = variablesDB.functions[leftPart].functionExpression;
		equation.concat('=', rightPart);
		equationSolver(equation);
	}

	function saveVariable(leftPart, rightPart) {
		
	}

	if (rightPart === '?') {
		if (Object.keys(variablesDB.complexes).includes(leftPart)) {
			saveAndOutput(variablesDB.complexes[leftPart]);
		} else if (Object.keys(variablesDB.matrices).includes(leftPart)) {
			saveAndOutput(variablesDB.matrices[leftPart]);
		} else {
			getLeftPartValue(leftPart);
		}
	} else if (rightPart.includes('?')) {
		rightPart = rightPart.split('?').join('');
		solveEquation(leftPart, rightPart);
	} else {
		saveVariable(leftPart, rightPart);
	}
}

function keyWordProcessor(inputString) {
	let ifKeyWord = false;
	switch (inputString) {
		case "history":
			console.log(history);
			ifKeyWord = true;
			break;
	}
	return ifKeyWord;
}

function inputProcessor(input) {
	let isInputValid;

	if (!keyWordProcessor(input)) {
		isInputValid = validator(input);
		if (isInputValid) {
			generalComputations(input);
		}
	}
}
stdin.addListener("data", d => {
	let input = d.toString().trim();

	inputProcessor(input);
});


// stdin.addListener("data", d => {
// 	validator(d.toString());
// 	let input = d.toString().trim();
// 	input = input.split('=');
// 	let stringWithVariables = input[1];
// 	if (input[1].trim() === '?') {
// 		stringWithVariables = input[0];
// 		input[0] = '?'
// 	}
// 	if (input[1].includes('?')) {
// 		input[0] = variableToValueChange(variablesDB, input[0]);
// 		input[1] = variableToValueChange(variablesDB, input[1]);
// 		input[1] = input[1].split('?').join('');
// 		Object.keys(variablesDB).forEach(variableName => {
// 			if (input[0].includes(variableName) && typeof variablesDB[variableName] === "object"
// 				&& variablesDB[variableName].functionName) {
// 					input[0] = variablesDB[variableName].functionExpression
// 			}
// 		});
// 		equationSolver(input.join('='))
// 	} else {
// 		input[1] = variableToValueChange(variablesDB, stringWithVariables);
// 		input[1] = func.functionRead(variablesDB, input[1]);
// 		input = input.join('=');
// 		let variableObject = parseAndCompute(input);
// 		if (input[0] !== '?') {
// 			variablesDB[variableObject.name] = variableObject.value;
// 		}
// 		output(variableObject);
// 	}
// });