const sqrt = module.require("./helper.js");

function quadratic_equation_solver (a, b, c) {
    let Discriminant;

    Discriminant = b * b - 4 * a * c;

    if (Discriminant > 0) {
        let solution_2 = ((-b - sqrt(Discriminant)) / (2 * a)).toFixed(6);
        let solution_1 = ((-b + sqrt(Discriminant)) / (2 * a)).toFixed(6);
        console.log("Discriminant is strictly positive, the two solution are:");
        console.log(solution_1);
        console.log(solution_2);
    }
    if (Discriminant === 0) {
        let solution = (- b / (2 * a)).toFixed(6);
        console.log("Discriminant equals 0. Single solution is:");
        console.log(solution);
    }
    if (Discriminant < 0) {
        let Real_part = -b / (2 * a).toFixed(6);
        let Imaginary_part  = (sqrt(-Discriminant) / (2 * a)).toFixed(6);
        console.log("Discriminant is less then 0. Solutions are complex numbers with real and imaginary part:");
        console.log(Real_part + " + " + Imaginary_part + "i");
        console.log(Real_part + " - " + Imaginary_part + "i");
    }

};

module.exports = quadratic_equation_solver;
