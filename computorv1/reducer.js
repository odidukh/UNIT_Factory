function natural_reduced_form(map) {
    let reduced_equation = '';

    map.forEach((value, key) => {
        if (key === 0) {
            if (value > 0) {
                if (reduced_equation.length === 0) {
                    reduced_equation = value.toString();
                } else {
                    reduced_equation = reduced_equation + '+' + value.toString();
                }
            } else if (value < 0) {
                reduced_equation = reduced_equation + value.toString();
            }
        } else if (key === 1) {
            if (value > 0) {
                if (reduced_equation.length === 0) {
                    reduced_equation = value.toString() + '*X';
                } else {
                    reduced_equation = reduced_equation + '+' + value.toString() + '*X';
                }
            } else if (value < 0) {
                reduced_equation = reduced_equation + value.toString() + '*X';
            }
        } else {
            if (value === 1) {
                if (reduced_equation.length === 0) {
                    reduced_equation = 'X^' + key.toString();
                } else {
                    reduced_equation = reduced_equation + '+' + 'X^' + key.toString();
                }
            } else if (value === -1) {
                if (reduced_equation.length === 0) {
                    reduced_equation = '-X^' + key.toString();
                } else {
                    reduced_equation = reduced_equation + '-' + 'X^' + key.toString();
                }
            } else if (value > 0) {
                if (reduced_equation.length === 0) {
                    reduced_equation = value.toString() + '*X^' + key.toString();
                } else {
                    reduced_equation = reduced_equation + '+' + value.toString() + '*X^' + key.toString();
                }
            } else if (value < 0) {
                reduced_equation = reduced_equation + value.toString() + '*X^' + key.toString();
            }
        }
    });

    reduced_equation = reduced_equation + '=0';

    return (reduced_equation.split('').join(' ').replace(/ \^ /g, '^'));
}

function usual_reduced_form(map) {
    let reduced_equation = '';

    map.forEach((value, key) => {
        if (value > 0) {
            if (reduced_equation.length === 0) {
                reduced_equation = value.toString() + '*X^' + key.toString();
            } else {
                reduced_equation = reduced_equation + '+' + value.toString() + '*X^' + key.toString();
            }
        } else if (value < 0) {
            reduced_equation = reduced_equation + value.toString() + '*X^' + key.toString();
        }
    });

    reduced_equation = reduced_equation + '=0';

    return (reduced_equation.split('').join(' ').replace(/ \^ /g, '^'));
}

function reducer(map, initial_equation) {
    if (initial_equation.includes("X^1") || initial_equation.includes("X^0")) {
        return usual_reduced_form(map);
    } else {
        return natural_reduced_form(map);
    }
}
module.exports = reducer;