/*
    2. ТРЕУГОЛЬНИК. Заданы три числа. Выясните,  какого вида треугольник с такими длинами сторон: 
    равносторонний, прямоугольный, равнобедренный или общего вида.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, a2, b2, c2;        

    cout << "Enter sides of triangle\n" << "Enter side a: ";
    cin >> a;
    cout << "Enter side b: ";
    cin >> b;
    cout << "Enter side c: ";
    cin >> c;
    
 	a2 = pow(a , 2);
    b2 = pow(b , 2);
    c2 = pow(c , 2);
    
    if(a + b > c && a + c > b && c + b > a){
        if(a == b || b == c || c == a){
            if(a == b && b == c)
            cout << "Triangle is equilateral (Ravnostoronnii)";
            else 
            cout << "Triangle is isosceles (ravnobedrennii)";
        } 
        else if (a2 == b2 + c2  ||
                 b2 == a2 + c2  ||
                 c2 == a2 + b2 )
            cout << "Triangle is rectangular (priamougolnii)";
        else 
            cout << "Triangle is simple"; 
    }
    else cout << "There is no triangle with the given sides";     

    return 0;
}
