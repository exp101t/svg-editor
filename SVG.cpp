#include "SVG.h"

void SVG::add(const string& tag_name, const prop_list& properties) {
    objects.push_back({
        tag_name, properties
    });
}

void SVG::save() {
    ofstream out(filename); out << SVG_HEAD;

    for (auto& object: objects) {
        out << "<" << object.tag_name;

        for (auto& prop: object.properties) {
            out << " " << prop.first << "=\"" << prop.second << "\"";
        }

        out << "/>";
    }

    out << "</svg>"; out.close();
}