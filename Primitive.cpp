#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef vector<pair<string, string>> prop_list;

struct Primitive {
    string tag_name;
    prop_list properties;
};