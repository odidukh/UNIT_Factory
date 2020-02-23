const allowed_signs = ['+', '-', '*', '^', '.'];
const allowed_letters = ['X', 'x'];
const allowed_numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];

function check_equal_sign(equation) {
    let count = 0;

    [...equation].forEach(char => {
        if (char === '=') {
            count++;
        }
    });

    if (count !== 1) {
        console.log("Error: wrong number of '=' sign");
        process.exit(0);
    }

    equation = equation.split('=');
    if (equation.length !== 2 || equation[0].length === 0 || equation[1].length === 0) {
        console.log("Error: wrong position of '=' sign");
        process.exit(0);
    }
}

function check_forbidden_signs (equation) {
    [...equation].forEach(char => {
        if (!allowed_signs.includes(char) && !allowed_letters.includes(char) && !allowed_numbers.includes(char)
            && !(char === '=')) {
            console.log("Error: unsupported character:\"", char, "\"");
            process.exit(0);
        }
    });
}

function check_signs_position (equation) {
    [...equation].forEach((char, index) => {
        if (allowed_signs.includes(char) && allowed_signs.includes(equation[index + 1])) {
            console.log("Typo error: after \"", char, "\" cannot be \"", equation[index + 1], "\" sign");
            process.exit(0);
        }
        if (char === '.' && (!allowed_numbers.includes(equation[index - 1]) || !allowed_numbers.includes(equation[index + 1]))) {
            console.log("Typo error: char '.' should be surrounded by numbers only");
            process.exit(0);
        }
        if (char === '*' && (!allowed_numbers.includes(equation[index - 1]) ||
            !allowed_letters.includes(equation[index + 1]))) {
            console.log("Typo error: need a number before '*' sign and a letter after");
            process.exit(0);
        }
        if (char === '^' && (!allowed_letters.includes(equation[index - 1]) &&
            !allowed_numbers.includes(equation[index + 1]))) {
            console.log("Typo error: need a letter before '^' sign and a number after");
            process.exit(0);
        }
        if (allowed_letters.includes(char) && ((allowed_letters.includes(equation[index + 1]) || allowed_numbers.includes(equation[index + 1])))) {
            console.log("Typo error: wrong character after 'X' letter");
            process.exit(0);
        }
         if (allowed_numbers.includes(char) && equation[index + 1] === '^') {
             console.log("Typo error: wrong character after number \"" + char + "\"");
             process.exit(0);
        }
    });
}

function check_point_count(elements_array) {
    elements_array.forEach(element => {
        let count = 0;
        [...element].forEach(char => {
            if (char === '.') {
                count++;
            }
        });
        if (count > 1) {
            console.log("Typo error: wrong number of '.' sign");
            process.exit(0);
        }
    })
}

function sign_inverse (string) {
    let temp_string = string;
    let shift = 0;
    if (string === "0") {
        temp_string = "0"
    } else {
        for (let i = 0; i < string.length; i++) {
            if (i === 0 && !allowed_signs.includes(string[0])) {
                temp_string = ['-', temp_string].join('');
                shift++;
            } else if (string[i] === '+') {
                temp_string = temp_string.substr(0, i + shift) + '-' + temp_string.substr(i + shift + 1);
            } else if (string[i] === '-') {
                temp_string = temp_string.substr(0, i + shift) + '+' + temp_string.substr(i + shift + 1);

            }
        }
    }
    return (temp_string);
}

function internal_operations(equation) {

    equation = equation.toUpperCase().split('=');
    [...equation[1]].forEach((char, index) => {
        if (char === '-') {
            equation[1][index] = '+'
        }
    });

    equation[1] = sign_inverse(equation[1]);

    equation = equation.map(function (string) {
        let temp_string = string;
        let shift = 0;
        for (let i = 0; i < string.length; i++) {
            if (string[i] === '-') {
                temp_string = [temp_string.slice(0, i + shift), '+', temp_string.slice(i + shift)].join('');
                shift++;
            }
        }
        return (temp_string);
    });

    let elements_arr = [];
    equation.forEach(function (array) {
        let temp_arr = array.split('+');
        temp_arr.forEach(function (elem) {
            if (elem.length) {
                elements_arr.push(elem);
            }
        })
    });

    check_point_count(elements_arr);

    return elements_arr;
}

function check_whole_degree(part) {
    if (part.includes('^')) {
        if (part.split('^')[1].includes('.')) {
            console.log("Error: a degree can only be a whole number");
            process.exit(0);
        }
        if (part.split('^')[1][0] === '0' && part.split('^')[1].length > 1) {
            console.log(("Typo error: '0' can be on the first place in the degree"));
            process.exit(0);
        }
    }
}


function array_to_map(array_of_terms) {
    let map_degree_coefficient = new Map([[0, 0], [1, 0], [2, 0]]);

    array_of_terms.forEach(term => {
        check_whole_degree(term);

        let minus = 1;
        let coefficient  = 0;
        let degree = 0;

        if (term[0] === '-') {
            minus = -1;
            term = term.substr(1);
        }

        if (term.includes('*') && term.includes('^')) {
            coefficient = parseFloat(term.split('*')[0]);
            degree = parseInt(term.split('*')[1].split('^')[1]);
        } else if (term.includes('*') && !term.includes('^')) {
            coefficient = parseFloat(term.split('*')[0]);
            degree = 1;
        } else if (!term.includes('*') && term.includes('^') && term[0] === 'X') {
            coefficient = 1;
            degree = parseInt(term.split('^')[1]);
        } else if (!term.includes('*') && !term.includes('^') && term[0] === 'X') {
            coefficient = 1;
            degree = 1;
        } else if (!term.includes('*') && term.includes('^') && term.includes('X')) {
            coefficient = parseFloat(term.split('X')[0]);
            degree = parseInt(term.split('^')[1]);
        } else if (!term.includes('*') && !term.includes('^') && term.includes('X')) {
            coefficient = parseFloat(term.split('X')[0]);
            degree = 1;
        } else {
            coefficient = parseFloat(term);
            degree = 0;
        }

        if (map_degree_coefficient.has(degree)) {
            map_degree_coefficient.set(degree, map_degree_coefficient.get(degree) + coefficient * minus);
        } else {
            map_degree_coefficient.set(degree, coefficient * minus);
        }
    });
    return (map_degree_coefficient);
}

function coefficients_with_power(input_string) {
    let equation = input_string.split(" ").join("");
    check_forbidden_signs(equation);
    check_equal_sign(equation);
    check_signs_position(equation);
    let elements_array = internal_operations(equation);

    return array_to_map(elements_array);
}

module.exports = coefficients_with_power;
