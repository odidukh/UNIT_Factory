module.exports = complexNumbers;

function complexNumbers(value) {
    let step = 0;
    let tempValue = value;
    for (let i = 0; i < tempValue.length; i++) {
        if (tempValue[i]  === '-') {
            value = value.substring(0, i + step) + '+' + value.substring(i + step);
            step++;
        }
    }
    let expression = String(value).split('+');
    let realPart = 0;
    let imaginaryPart = 0;
    expression.forEach(part => {
        if (part.includes('i')) {
            part = part.replace(new RegExp('i'), '');
            if (part === '-') {
                part = '-1';
            }
            if (part === '') {
                part = '1';
            }
            imaginaryPart += parseFloat(part);
        } else {
            if (part !== '') {
                realPart += parseFloat(part);
            }
        }
    });
    let sign = '+ ';
    if (imaginaryPart < 0) {
        imaginaryPart = -imaginaryPart;
        sign = '- '
    }
    if (imaginaryPart === 1) {
        imaginaryPart = '';
    }
    if (imaginaryPart === 0) {
        return realPart;
    }
    return realPart.toString() + ' ' + sign + imaginaryPart.toString() + 'i';
}