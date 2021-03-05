/*
     [+]. (необязательно) 2->10. Переведите число из двоичной системы в десятичную.
*/    

var number = prompt("Enter number");
var result = 0;

function f(obj){
    for(var i = obj.length - 1; i >= 0 ; i--){
        result += +obj[i] * (Math.pow(2, i));
    }
    return(result);
}

console.log(f(number));