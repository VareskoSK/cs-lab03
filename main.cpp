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
        CURL *curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            res = curl_easy_perform(curl);
            if (res)
            {
                cerr << curl_easy_strerror(res) << endl;
                exit(1);
            }
            curl_easy_cleanup(curl);
        }
        return 0;
    }
    const auto input = read_input(cin, true);
    const auto bins = make_histogram(input.numbers, input.bin_count);
    show_histogram_svg(bins, input.bin_height, input.bin_count);
    return 0;
}
