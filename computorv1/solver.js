function quadratic_equation_solver (a, b, c) {
    var Discriminant;

    Discriminant = b * b - 4 * a * c;

    if (Discriminant > 0) {
        var solution_2 = (-b - Math.sqrt(Discriminant)) / (2 * a);
        var solution_1 = (-b + Math.sqrt(Discriminant)) / (2 * a);
        console.log("Discriminant is strictly positive, the two solution are:");
        console.log(solution_1);
        console.log(solution_2);
    }
    if (Discriminant === 0) {
        var solution = - b / (2 * a);
        console.log("Discriminant equals 0. Single solution is:");
        console.log(solution);
    }
    if (Discriminant < 0) {
        var Real_part = -b / (2 * a);
        var Imaginary_part  = Math.sqrt(-Discriminant) / (2 * a);
        console.log("Discriminant is less then 0. Solutions are irrational numbers with real and imaginary part:");
        console.log(Real_part + " + " + Imaginary_part + "i");
        console.log(Real_part + " - " + Imaginary_part + "i");
    }

};

module.exports = quadratic_equation_solver;
