#include "../dasmig/namegen.hpp"
#include <iostream>

using ng = dasmig::ng;

std::wostream &operator<<(std::wostream &wos, const ng::culture &c)
{
    switch (c)
    {
    case ng::culture::american:
        return wos << "American";
    case ng::culture::argentinian:
        return wos << "Argentinian";
    case ng::culture::australian:
        return wos << "Australian";
    case ng::culture::brazilian:
        return wos << "Brazilian";
    case ng::culture::british:
        return wos << "British";
    case ng::culture::bulgarian:
        return wos << "Bulgarian";
    case ng::culture::canadian:
        return wos << "Canadian";
    case ng::culture::chinese:
        return wos << "Chinese";
    case ng::culture::danish:
        return wos << "Danish";
    case ng::culture::finnish:
        return wos << "Finnish";
    case ng::culture::french:
        return wos << "French";
    case ng::culture::german:
        return wos << "German";
    case ng::culture::italian:
        return wos << "Italian";
    case ng::culture::kazakh:
        return wos << "Kazakh";
    case ng::culture::mexican:
        return wos << "Mexican";
    case ng::culture::norwegian:
        return wos << "Norwegian";
    case ng::culture::polish:
        return wos << "Polish";
    case ng::culture::portuguese:
        return wos << "Portuguese";
    case ng::culture::russian:
        return wos << "Russian";
    case ng::culture::spanish:
        return wos << "Spanish";
    case ng::culture::swedish:
        return wos << "Swedish";
    case ng::culture::turkish:
        return wos << "Turkish";
    case ng::culture::ukrainian:
        return wos << "Ukrainian";
    default:
        return wos << "Unknown culture";
    }
}

std::wostream &operator<<(std::wostream &wos, const ng::gender &g)
{
    switch (g)
    {
    case ng::gender::m:
        return wos << "male";
    case ng::gender::f:
        return wos << "female";
    default:
        return wos << "Unknown gender";
    }
}

int main()
{
    ng::instance().load("../resources");

    // Generate 10 names in the same random culture and gender.
    auto name = ng::instance().get_name().append_surname();
    std::wcout << name.get_culture() << L"|" << name.get_gender()
               << L": " << name
               << std::endl;

    auto culture = name.get_culture();
    auto gender = name.get_gender();
    for (int i = 1; i < 10; ++i)
    {
        auto name = ng::instance().get_name(gender, culture).append_surname(culture);
        std::wcout << name.get_culture() << L"|" << name.get_gender()
                   << L": " << name
                   << std::endl;
    }

    return 0;
}