const quadratic_equation_solver = require("./solver");if (process.argv.length < 3) {	console.log("Usage: ./computor \"equation\"");	console.log("Example: ./computor \"1 * X^2 + 2 * X^1 + 3 * X^0 = 0\"");	process.exit(0);}let equation = process.argv.slice(2).join("").split(" ").join("").split("=");if (equation.length !== 2) {	console.log("Usage: ./computor \"equation\"");	console.log("Example: ./computor \"1 * X^2 + 2 * X^1 + 3 * X^0 = 0\"");	process.exit(0);}const allowed_signs = ['+', '-', '*', '^'];const allowed_letters = ['X', 'x'];const allowed_numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];function check_forbidden_symbol(symbol) {	let forbidden_char;	let flag_1 = 0;	let flag_2 = 0;	let flag_3 = 0;	allowed_signs.forEach(function (allowed_char) {		if (allowed_char === symbol)			flag_1 = 1;	});	allowed_letters.forEach(function (allowed_char) {		if (allowed_char === symbol)			flag_2 = 1;	})	allowed_numbers.forEach(function (allowed_char) {		if (allowed_char === symbol)			flag_3 = 1;	})	if (!(flag_1 || flag_2 || flag_3)) {		forbidden_char = symbol;		console.log("Error: unsupported character : \"", forbidden_char, "\"");	}}equation.forEach(function (array) {		[...array].forEach(function (char) {			check_forbidden_symbol(char);		})});const main = (args) => {	let a = args[0];	let b = args[1];	let c = args[2];	quadratic_equation_solver(a, b, c);};if (require.main === module){	main(process.argv.slice(2));}