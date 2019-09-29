const allowed_signs = ['+', '-', '*', '^'];
const allowed_letters = ['X', 'x'];
const allowed_numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];

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
        if (char === '+' && !allowed_numbers.includes(equation[index + 1])) {
            console.log("Typo error: need a number after '+' sign");
            process.exit(0);
        }
        if (char === '-' && !allowed_numbers.includes(equation[index + 1])) {
            console.log("Typo error: need a number after '-' sign");
            process.exit(0);
        }
        if (char === '*' && (!allowed_numbers.includes(equation[index - 1]) ||
            !allowed_letters.includes(equation[index + 1]))) {
            console.log("Typo error: need a number before '*' sign and a letter after");
            process.exit(0);
        }
        if (char === '^' && (!allowed_letters.includes(equation[index - 1]) ||
            !allowed_numbers.includes(equation[index + 1]))) {
            console.log("Typo error: need a letter before '^' sign and a number after");
            process.exit(0);
        }
        if (allowed_letters.includes(char) && (equation[index + 1] !== '^')) {
            console.log("Typo error: need '^' sign after 'X' letter");
            process.exit(0);
        }
    });
}

function internal_operations(equation) {
    equation = equation.split('=');
    [...equation[1]].forEach((char, index) => {
        if (char === '-') {
            equation[1][index] = '+'
        }
    });

    function sign_inverse (string) {
        let temp_string = string;
        let shift = 0;
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
        return (temp_string);
    }

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
    return elements_arr;
}


function array_to_map(elements_arr) {
    let map_exp_coeff = new Map();

    for (let i = 0; i < elements_arr.length; i++) {

        let temp_arr = elements_arr[i].split('*');
        if (temp_arr.length === 1) {
            if (allowed_letters.includes(temp_arr[0]) && temp_arr[0].length === 1) {
                if (map_exp_coeff.has(1)) {
                    map_exp_coeff.set(1, map_exp_coeff.get(1) + 1);
                } else {
                    map_exp_coeff.set(1, 1);
                }
            }
            let sub_temp_arr = temp_arr[0].split('^');
            if (sub_temp_arr.length !== 2){
                if (map_exp_coeff.has(0)) {
                    map_exp_coeff.set(parseInt('0'), parseFloat(map_exp_coeff.get(0)) + parseFloat(sub_temp_arr[0]));
                } else {
                    map_exp_coeff.set(parseInt('0'), parseFloat(sub_temp_arr[0]));
                }
            } else {
                if (map_exp_coeff.has(sub_temp_arr[1])) {
                    map_exp_coeff.set(parseInt(sub_temp_arr[1]), parseFloat(map_exp_coeff.get(parseInt(sub_temp_arr[1]) + 1)));
                } else {
                    map_exp_coeff.set(parseInt(sub_temp_arr[1]), 1);
                }
            }
        } else {
            let sub_temp_arr = temp_arr[1].split('^');
            if (map_exp_coeff.has(parseInt(sub_temp_arr[1]))) {
                map_exp_coeff.set(parseInt(sub_temp_arr[1]), map_exp_coeff.get(parseInt(sub_temp_arr[1])) + parseFloat(temp_arr[0]));
            } else {
                map_exp_coeff.set(parseInt(sub_temp_arr[1]), parseFloat(temp_arr[0]));
            }
        }
        console.log(map_exp_coeff);
    }
}


coefficients_with_power = function () {

    let equation = process.argv.slice(2).join("").split(" ").join("");
    check_forbidden_signs(equation);
    check_signs_position(equation);
    elements_array = internal_operations(equation);

    return array_to_map(elements_array);
};

module.exports = coefficients_with_power;
