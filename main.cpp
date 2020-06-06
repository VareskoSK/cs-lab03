#include <iostream>
#include <vector>
#include "histogram.h"
#include "SVG.h"

using namespace std;

int main()
{
    size_t number_count;
    size_t bin_height;
    cerr << "Enter number count: ";
    cin >> number_count;
    if (number_count==0)
        return 1;
    const auto numbers = input_numbers(cin, number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    if (bin_count==0)
        return 1;
    cerr << "Enter bin height: ";
    cin >> bin_height;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins, bin_height, bin_count);
    return 0;
}
