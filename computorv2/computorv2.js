// const parseAndCompute = require('./parser');
const validator = require('./validator');
const realNumberComp = require('./realNumCalculation');
const output = require('./stdout');
const func = require('./functions');
const equationSolver = require('./functionComputor');
const matrix = require('./matrixOperations');
const complexNumbers = require('./complex');

let stdin = process.openStdin();

global.variablesDB = {
	'real'	   : {},
	'functions': {},
	'matrices' : {},
	'complexes': {},
};

global.history = '';


global.saveAndOutput = function (output) {
	history.concat('\n', output);
	console.log(output);
};

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
		rightPart = variableToValue(variablesDB.real, rightPart);
		let equation = variablesDB.functions[leftPart].functionExpression;
		let variable = variablesDB.functions[leftPart].variableName;
		equation = equation + '=' + rightPart;
		equationSolver(equation, variable);
	}

	function variableTypeSelector(varName, expression) {
		expression = variableToValue(variablesDB.real, expression);
		if (varName.includes('(')) {
			expression = func.functionRead(variablesDB.functions, expression);
			let functionObject = func.functionProcessor(varName, expression);
			variablesDB.functions[varName] = functionObject;
			console.log(functionObject.functionExpression);
		} else if (expression.includes('[')) {
			let matrixObj = matrix.matrix(expression);
			variablesDB.matrices[varName] = matrixObj.matrix;
			let matrixExp = matrixObj.matrix.split(';');
			matrixExp.forEach(row => {
				console.log('[ ' + row.substring(1, row.length - 1).split(',').join(' , ') + ' ]')
			})
		} else if (expression.includes('i')) {
			let complex = complexNumbers(expression);
			variablesDB.complexes[varName] = complex;
			console.log(complex)
		} else {
			let realNum = realNumberComp(expression);
			variablesDB.real[varName] = realNum;
			console.log(realNum);
		}
	}


	function saveVariable(leftPart, rightPart) {
		variableTypeSelector(leftPart, rightPart);
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