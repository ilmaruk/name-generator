#include "../dasmig/namegen.hpp"
#include <iostream>

using ng = dasmig::ng;

std::wostream &operator<<(std::wostream &wos, const ng::culture &c)
{
    switch (c)
    {
    case ng::culture::albanian:
        return wos << "Albania";
    case ng::culture::american:
        return wos << "American";
    case ng::culture::argentinian:
        return wos << "Argentinian";
    case ng::culture::australian:
        return wos << "Australian";
    case ng::culture::austrian:
        return wos << "Austrian";
    case ng::culture::belgian:
        return wos << "Belgian";
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
    case ng::culture::croatian:
        return wos << "Croatia";
    case ng::culture::czech:
        return wos << "Czechia";
    case ng::culture::danish:
        return wos << "Danish";
    case ng::culture::dutch:
        return wos << "Dutch";
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
    case ng::culture::slovenian:
        return wos << "Slovenia";
    case ng::culture::spanish:
        return wos << "Spanish";
    case ng::culture::swedish:
        return wos << "Swedish";
    case ng::culture::swiss:
        return wos << "Swiss";
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

constexpr ng::culture all_cultures[] = {
    ng::culture::albanian,
    ng::culture::american,
    ng::culture::argentinian,
    ng::culture::australian,
    ng::culture::austrian,
    ng::culture::belgian,
    ng::culture::brazilian,
    ng::culture::british,
    ng::culture::bulgarian,
    ng::culture::canadian,
    ng::culture::chinese,
    ng::culture::croatian,
    ng::culture::czech,
    ng::culture::danish,
    ng::culture::dutch,
    ng::culture::finnish,
    ng::culture::french,
    ng::culture::german,
    ng::culture::italian,
    ng::culture::kazakh,
    ng::culture::mexican,
    ng::culture::norwegian,
    ng::culture::polish,
    ng::culture::portuguese,
    ng::culture::russian,
    ng::culture::slovenian,
    ng::culture::spanish,
    ng::culture::swedish,
    ng::culture::swiss,
    ng::culture::turkish,
    ng::culture::ukrainian,
};

int main()
{
    ng::instance().load("../resources");

    // Generate one name per gender and culture.
    for (const auto &culture : all_cultures)
    {
        auto him = ng::instance().get_name(ng::gender::f, culture).append_surname();
        auto her = ng::instance().get_name(ng::gender::m, culture).append_surname();
        std::wcout << culture << L" | "
                   << her << L" | "
                   << him << std::endl;
    }

    return 0;
}