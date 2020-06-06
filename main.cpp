#include <iostream>
#include <vector>
#include "histogram.h"
#include "SVG.h"
#include <curl/curl.h>

using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
    size_t bin_height;
};

Input
read_input(istream& in, bool prompt)
{
    Input data;

    if (prompt)
        cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;
    if (prompt)
        cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    if (prompt)
        cerr << "Enter column count: ";
    in >> data.bin_count;
    if (prompt)
        cerr << "Enter bin height: ";
    in >> data.bin_height;

    return data;
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        for (int i = 0; i < argc; i++)
        {
            cout << "argv[" << i << "] = " << argv[i] << '\n';
        }
        return 0;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin, true);
    const auto bins = make_histogram(input.numbers, input.bin_count);
    show_histogram_svg(bins, input.bin_height, input.bin_count);
    return 0;
}
