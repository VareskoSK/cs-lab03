#include "SVG.h"
#include "histogram.h"
#include <iostream>
#include <vector>

using namespace std;

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
 cout << "<rect x='"<< x << "' y='" <<y<<"' width='" <<width <<"' height='" <<height <<"' stroke='"<< stroke <<"' fill='"<<fill<<"'/>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<< baseline <<"'>"<<text<<"</text>\n";
}

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void show_histogram_svg(const vector<size_t>& bins, size_t bin_height, size_t bin_count)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 700;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BLOCK_WIDTH = 10;
    if (! check_height)
        bin_height = IMAGE_HEIGHT / bin_count;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins)
    {
    const double bin_width = BLOCK_WIDTH * bin;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, bin_height, "blue", "blue");
    top += bin_height;
    }
    svg_end();
}
