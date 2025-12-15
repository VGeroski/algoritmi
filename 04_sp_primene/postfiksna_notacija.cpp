/**
 * Neka je dat izraz u posfiksnoj notaciji. Odrediti njegovu vrednost.
 * Npr vrednost izraza 12 5 + 4 + je 21.
 */

#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <iostream>

// Funkcija koja parsira nisku po " " (belini)
std::vector<std::string> parse_string(const std::string &exp)
{
    // kopija niske, ne zelimo da menjamo originalnu (poslata po const ref)
    std::string s = exp;
    std::vector<std::string> parts;

    int pos = 0;

    // Dok god nailazimo na na " " (space) krecemo se kroz nisku
    // std::string:npos govori da smo dosli do kraja niske
    while ((pos = s.find(" ")) != std::string::npos)
    {
        // uzimamo deo niske
        parts.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }

    parts.push_back(s.substr(0, pos));

    return parts;
}

std::vector<std::string> parse_string_stream(const std::string &exp)
{
    std::stringstream ss(exp);
    std::vector<std::string> parts;
    std::string token;

    while (ss >> token)
        parts.push_back(token);

    return parts;
}

int main()
{
    std::stack<int> s;

    std::string expression = "5 7 + 6 2 - *";

    // uzimamo sve 'delove' izraza koji nisu beline (split po ' ')
    std::vector<std::string> parts = parse_string_stream(expression);
    // for (const std::string &s : parts)
    //     std::cout << s << " ";

    for (const auto &part : parts)
    {
        if (part == "+" || part == "-" || part == "*" || part == "/")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (part == "+")
                s.push(a + b);
            else if (part == "*")
                s.push(a * b);
            else if (part == "-")
                s.push(a - b);
            else if (part == "/")
                s.push(a / b);
        }
        else
            s.push(std::stoi(part));
    }

    std::cout << "Resenje je: " << s.top() << std::endl;

    return 0;
}