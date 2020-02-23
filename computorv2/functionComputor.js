const solver = require("./solver");const parser = require("./functionParser");const reducer = require("./reducer");module.exports = functionComputor;function polynomial_degree_getter(map_degree_coeff) {	map_degree_coeff.forEach((key, value) => {		if (key === 0) {			map_degree_coeff.delete(value);		}	});	let degree_array = Array.from(map_degree_coeff.keys());	if (degree_array.length === 0) {		return 0;	}	return Math.max.apply(null, degree_array);}function functionComputor(func) {	let input_string = func;	let map_degree_coeff = parser(input_string);	let polynomial_degree = polynomial_degree_getter(map_degree_coeff);	console.log(parser((input_string)));	if (reducer(map_degree_coeff, process.argv.slice(2).join('').toUpperCase())) {		console.log("Reduced form:", reducer(map_degree_coeff, process.argv.slice(2).join('').toUpperCase()));	}	console.log("Polynomial degree:", polynomial_degree);	if (polynomial_degree > 2) {		console.log("The polynomial degree is strictly greater than 2, I can't solve.");		process.exit(0);	}	let a = map_degree_coeff.get(2);	if (a === undefined) {		a = 0;	}	let b = map_degree_coeff.get(1);	if (b === undefined) {		b = 0;	}	let c = map_degree_coeff.get(0);	if (c === undefined) {		c = 0;	}	solver(a, b, c);}