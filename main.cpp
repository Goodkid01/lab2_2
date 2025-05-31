#include <iostream>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>


int main() 
{
    int x;
    int i;
    std:: cin>>x;
    std:: cin>>i;
    x|= (1 << i);
    std:: cout<<x<< std::endl;
}
