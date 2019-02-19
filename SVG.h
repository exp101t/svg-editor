#ifndef SVG_EDITOR_SVG_H
#define SVG_EDITOR_SVG_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Primitive.cpp"

class SVG {
private:
    char* filename; string SVG_HEAD;
    vector<Primitive> objects;
    size_t height, width;
public:
    void add(const string&, const prop_list&);
    void save();

    SVG (char* name = "test.svg", size_t width = 512, size_t height = 512)
        : filename(name), width(width), height(height), SVG_HEAD(
            R"(<svg xmlns="http://www.w3.org/2000/svg" height=")" +
            to_string(height) + R"(px" width=")" +
            to_string(width)  + R"(px">)"
        ) {};
};

#endif //SVG_EDITOR_SVG_H