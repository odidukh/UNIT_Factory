module.exports = {
	functionCalculator,
	functionProcessor,
	functionRead
};
const realNumCalc = require('./realNumCalculation');

function functionProcessor(funcName, func) {
	let resObj = {};
	let regExp = /\(([^)]+)\)/;
	let variableName = regExp.exec(funcName);

	resObj.variableName = variableName[1];
	resObj.functionName = funcName.substring(0, funcName.indexOf('('));
	resObj.functionExpression = func;
	return resObj;
}

function functionRead(variables, input) {
	Object.keys(variables).forEach(funcName => {

	});
	return input;
}

function functionCalculator(funcValue, funcVariable, variableValue) {
	let calcRes;

	funcValue = funcValue.replace(new RegExp("\\b" + funcVariable + "\\b", 'g'), variableValue);
	calcRes = realNumCalc(funcValue);
	return calcRes;
}

