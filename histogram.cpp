#include "histogram.h"
#include <vector>

using namespace std;
//this message makes no sense
void find_minmax(vector<double> numbers, double& min, double& max)
{
  min = numbers[0];
  max = numbers[0];
    for (double number : numbers)
 {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
 }
 return;
}
