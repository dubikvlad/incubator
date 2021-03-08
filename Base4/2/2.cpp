/*
    2. ТРЕУГОЛЬНИК. Заданы три числа. Выясните,  какого вида треугольник с такими длинами сторон: 
    равносторонний, прямоугольный, равнобедренный или общего вида.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int sideA, sideB, sideC,
        sideA2 = pow(sideA , 2),
        sideB2 = pow(sideB , 2),
        sideC2 = pow(sideC , 2);

    cout << "Enter sides of triangle\n";
    cin >> sideA >> sideB >> sideC;
    
    if(sideA == sideB or sideB == sideC or sideC == sideA){
        if(sideA == sideB and sideB == sideC)
        cout << "Triangle is equilateral (Ravnostoronnii)";
        else 
        cout << "Triangle is isosceles (ravnobedrennii)";
    } 
    else if ((sideA2 == (sideB2 + sideC2) && (sideB2 == (sideA2 - sideC2)) && (sideC2 == (sideA2 - sideB2))) ||
             (sideB2 == (sideA2 + sideC2) && (sideA2 == (sideB2 - sideC2)) && (sideC2 == (sideB2 - sideA2))) ||
             (sideC2 == (sideA2 + sideB2) && (sideA2 == (sideC2 - sideB2)) && (sideB2 == (sideC2 - sideA2))))
        cout << "Triangle is rectangular (priamougolnii)";
    else 
        cout << "Triangle is simple"; 

    return 0;
}
