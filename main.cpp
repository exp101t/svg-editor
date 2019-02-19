#include <iostream>
#include "SVG.cpp"
using namespace std;

int main() {
    SVG test = SVG();

    test.add("line", {
            {"x1", "0"},
            {"y1", "0"},
            {"x2", "300"},
            {"y2", "200"},
            {"stroke-width", "1"},
            {"stroke", "rgb(0,255,0)"}
    });

    test.save();
}