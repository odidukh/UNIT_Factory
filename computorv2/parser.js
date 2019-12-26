function addition(num1, num2) {
	let sum = 0;
	sum = num1 + num2;

	return sum;
}

function subtraction(num1, num2) {
	let difference;
	difference = num1 - num2;

	return difference;
}

function multiplication(num1, num2) {
	let product;
	product = num1 * num2;

	return product;
}

function power(number, power) {
	let result = 1;
	for (let i = 0; i < power; i++) {
		result = result * number;
	}

	return result;
}

function matrixScalarMultiplication(num, matrix) {
	return 0;
}

function matrixMultiplication(matrix1, matrix2) {

}


function division(num1, num2) {
	let quotient;
	quotient = num1 / num2;

	return quotient;
}

function modulo(num1, num2) {
	let remainder;
	remainder = num1 % num2;

	return remainder;
}


function complexNumbers(value) {

}

function matrix(value) {
	return undefined;
}

function computations(expression) {
	expression = String(expression).split('+');
	let result = 0;
	for (let i = 0; i < expression.length; i++) {
		while (String(expression[i]).match(/[*%\/]/)) {
			let calcRes = 0;
			let sign1 = null;
			let sign2 = null;
			for (let j = 0; j < expression[i].length; j++) {
				let char = expression[i][j];
				if (char === '*' || char === '/' || char === '%') {
					if (sign1 === null) {
						sign1 = char;
					} else {
						sign2 = char;
						break;
					}
				}
			}
			let number;
			if (sign2) {
				number = expression[i].substring(0, expression[i].indexOf(sign2));
			}

			let operationalString = expression[i];
			if (sign2) {
				operationalString = number;
			}
			operationalString = operationalString.split(sign1);
			switch (sign1) {
				case '*':
					calcRes = multiplication(parseFloat(operationalString[0]), parseFloat(operationalString[1]));
					break;
				case '/':
					calcRes = division(parseFloat(operationalString[0]), parseFloat(operationalString[1]));
					break;
				case '%':
					calcRes = modulo(parseFloat(operationalString[0]), parseFloat(operationalString[1]));
					break;
			}
			if (sign2) {
				expression[i] = calcRes + expression[i].substring(expression[i].indexOf(sign2) + 1);
			} else {
				expression[i] = calcRes;
			}
		}
	}
	expression.forEach(number => {
		result += parseFloat(number);
	});
	return result;
}

function sequence(expression) {
	let computedPart = 0;
	if (expression.includes('(')) {
		sequence(expression.substring(expression.indexOf('(') + 1));
		expression = expression.substring(0, expression.indexOf('('));
	}
	console.log(expression);
	console.log(computations(expression));
	return (expression + computations(expression));
}

function realNumbers(expression) {
	let step = 0;
	let tempExpression = expression;
	for (let i = 0; i < tempExpression.length; i++) {
		if (tempExpression[i]  === '-') {
			expression = expression.substring(0, i + step) + '+' + expression.substring(i + step);
			step++;
		}
	}
	return sequence(expression);
}

function correctTypeParser(value) {
	if (value.includes('i')) {
		return complexNumbers(value);
	} else if (value.includes('[')) {
		return matrix(value);
	} else if (!(value.match(/[a-zA-Z]/))) {
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