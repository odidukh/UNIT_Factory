module.exports = {
	functionCalculator,
	functionProcessor,
	functionRead
};
const realNumCalc = require('./realNumCalculation');

function isCharNumber(c){
	return c >= '0' && c <= '9';
}

function functionProcessor(funcName, func) {
	let resObj = {};
	let regExp = /\(([^)]+)\)/;
	let variableName = regExp.exec(funcName)[1];

	let splitedFunc = func.split(variableName);
	for (let i = 0; i < splitedFunc.length - 1; i++) {
		if (isCharNumber(splitedFunc[i].charAt(splitedFunc[i].length - 1))
			|| splitedFunc[i].charAt(splitedFunc[i].length - 1) === ')') {
			splitedFunc[i] = splitedFunc[i] + '*'
		}
	}
	func = splitedFunc.join(variableName);
	let symbols = ['+', '-', '*', '/', '%'];
	for (let i = 0; i < symbols.length; i++) {
		if(func.includes(symbols[i])) {
			func = func.split(symbols[i]).join(' ' + symbols[i] + ' ')
		}
	}
	resObj.variableName = variableName;
	resObj.functionName = funcName.substring(0, funcName.indexOf('('));
	resObj.functionExpression = func;
	return resObj;
}

function functionRead(variables, input) {
	Object.keys(variables).forEach(variableName => {
		if (input.includes(variableName) && typeof variables[variableName] === "object"
			&& variables[variableName].functionName) {
			while (input.includes(variableName)) {
				let funcExp = variables[variableName].functionExpression;
				let functionVariable = variables[variableName].variableName;
				let roundBracketsCounter = 0;
				let replaceVariable = '';
				let substr = input.substring(input.indexOf(variableName) + variableName.length);
				for (let i = 0; i < substr.length; i++) {
					if (substr.charAt(i) === '(') {
						roundBracketsCounter++;
					} else if (substr.charAt(i) === ')') {
						roundBracketsCounter--;
						if (roundBracketsCounter === 0) {
							replaceVariable = substr.substring(0, i + 1);
							break;
						}
					}
				}
				funcExp = funcExp.replace(new RegExp("\\b" + functionVariable + "\\b", 'g'), replaceVariable);
				let fullReplaceable = variableName + replaceVariable;
				let fullReplacing = '(' + funcExp + ')';
				input = input.replace(fullReplaceable, fullReplacing);
			}
		}
	});
	return input;
}

function functionCalculator(funcValue, funcVariable, variableValue) {
	let calcRes;

	funcValue = funcValue.replace(new RegExp("\\b" + funcVariable + "\\b", 'g'), variableValue);
	calcRes = realNumCalc(funcValue);
	return calcRes;
}

