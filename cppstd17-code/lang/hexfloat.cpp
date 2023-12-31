#include <iostream>
#include <iomanip>

int main() {
    // init list of floating-point values:
    std::initializer_list<double> values{
            0x1p4,        // 16
            0xA,          // 10
            0xAp2,        // 40
            5e0,          // 5
            0x1.4p+2,     // 5
            1e5,          // 100000
            0x1.86Ap+16,  // 100000
            0xC.68p+2,    // 49.625
    };

    // print all values both as decimal and hexadecimal value:
    for ( double d : values )
    {
        std::cout << "dec: " << std::setw(6) << std::defaultfloat << d
                  << "  hex: " << std::hexfloat << d << '\n';
    }
}

