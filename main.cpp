#include <iostream>
#include <vector>
#include <sstream>
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

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    size_t data_size = item_size * item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    (*buffer).write(reinterpret_cast<const char*>(items), data_size);
    return data_size;
}
Input
download(const string& address) {
    stringstream buffer;
    double download_speed;

    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        res = curl_easy_perform(curl);
        if(CURLE_OK == res) {
            res = curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD_T, &download_speed);
            if(CURLE_OK == res) {
                cerr << "download speed = " << download_speed << endl;
            }
        }
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);


        res = curl_easy_perform(curl);
        if (res) {
            cerr << curl_easy_strerror(res) << endl;
            exit(1);
        }
    }
    curl_easy_cleanup(curl);
    return read_input(buffer, false);
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
