#include "image.h"
#include <iostream>

using namespace std;

int main() { 
    
    igg::Image image(4, 4);
    
    cout << image.rows() << endl;
    cout << image.cols() << endl;

    cout << image.Size() << endl;

    image.at(3, 3) = 1;
    cout << image.at(3, 0) << endl;
    cout << image.at(3, 3) << endl; 
    
    
}