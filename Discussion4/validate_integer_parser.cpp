// validate_integer_parser.cpp
// https://stackoverflow.com/questions/78134690/regex-match-a-pattern-that-only-contains-one-set-of-numeral-and-not-more
#include <cctype>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <string_view>

std::string OP_validate_integer(const std::string& input)
try {
    double d = std::stof(std::regex_replace(input, std::regex(R"([^\-0-9.]+)"), ""));
    return std::to_string(static_cast<int>(std::round(d)));
}
catch (std::exception const& e) {
    return e.what();
}
bool is_digit(unsigned const char c) {
    return std::isdigit(c);
}
bool is_sign(const char c) {
    return c == '+' || c == '-';
}
int validate_integer(std::string const& s)
{
    enum : std::string::size_type { one = 1u };
    std::string::size_type i{};

    // skip over prefix
    while (i < s.length())
    {
        if (is_digit(s[i]) || is_sign(s[i])
            && i + one < s.length()
            && is_digit(s[i + one]))
            break;
        ++i;
    }

    // throw if nothing remains
    if (i == s.length())
        throw std::runtime_error("validation failed");

    // parse integer 
    // due to foregoing checks, this cannot fail
    if (s[i] == '+')
        ++i;  // `std::from_chars` does not accept leading plus sign.
    auto const first{ &s[i] };
    auto const last{ &s[s.length() - one] + one };
    int n;
    auto [end, ec] { std::from_chars(first, last, n) };
    i += end - first;

    // skip over suffix
    while (i < s.length() && !is_digit(s[i]))
        ++i;

    // throw if anything remains
    if (i != s.length())
        throw std::runtime_error("validation failed");

    return n;
}
void test(std::ostream& log, bool const expect, std::string s)
{
    std::streamsize const w{ 46 };
    try {
        auto n = validate_integer(s);
        log << std::setw(w) << s << " : " << std::setw(10) << n
            << ", OP : " << OP_validate_integer(s) << '\n';
    }
    catch (std::exception const& e) {
        log << std::setw(w) << s << " : " << e.what()
            << (expect ? "" : "  (as expected)")
            << ", OP : " << OP_validate_integer(s) << '\n';
    }
}
int validate_integer_parser_main()
{
    auto& log{ std::cout };
    log << std::left;

    test(log, true, "<2112>");
    test(log, true, "[(2112)]");
    test(log, true, "\"2112, \"");
    test(log, true, "-2112");
    test(log, true, ".2112");
    test(log, true, "<span style = \"numeral\">2112</span>");
    log.put('\n');

    test(log, true, "++42");
    test(log, true, "--42");
    test(log, true, "+-42");
    test(log, true, "-+42");
    test(log, true, "- 42");
    log.put('\n');
    