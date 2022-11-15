#include <iostream>
#include <nlohmann/json.hpp>

struct int_values{
    int a{};
    int b{};
    int c{};
    int d{};
    int e{};
    int f{};
    // Für Fall 3(spart die Schreibarbeit von Fall 2)
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(int_values, a,b,c,d,e,f)
};

int main()
{
    // Fall 1
    std::vector<int> int_vec{1,2,3,4,5,6};
    // Fall 2
    int_values test_object{6,5,4,3,2,1};
    // Zuweisung Fall 1
    nlohmann::json json_object{int_vec};
    nlohmann::json json_object2{{"Zahlenreihe", int_vec}, {"Zufall", 1}};
    // Zuweisung Fall 2
    nlohmann::json test_json{{"a", test_object.a},
                            {"b",test_object.b},
                            {"c",test_object.c},
                            {"d", test_object.d},
                            {"e", test_object.e},
                            {"f", test_object.f}};
    // Zuweisung Fall 3
    nlohmann::json test_json2=test_object;

    std::cout << json_object << "\n";
    std::cout << json_object.dump() << "\n";
    std::cout << json_object2.dump() << "\n";
    std::cout << test_json.dump() << "\n";
    std::cout << test_json2.dump() << "\n";

    return 0;
}
