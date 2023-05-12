#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::getline;
using std::ifstream;
using std::left;
using std::map;
using std::ofstream;
using std::setw;
using std::string;
using std::stringstream;
using std::transform;
using std::vector;

vector<string> links;
map<string, vector<int>> words;
string filename;

string file()
{
    system("ls *.txt");
    cout << "Iveskite failo pavadinima: " << endl;
    cin >> filename;
    bool badFile;

    do
    {
        try
        {
            ifstream in(filename);
            if (!in.good())
                throw 404;
            else
            {
                in.close();
                badFile = false;
            }
        }
        catch (int exception)
        {
            badFile = true;
            cout << "Duomenu failas " << filename << " neegzistuoja. Iveskite esamo failo varda: " << endl;
            cin >> filename;
        }
    } while (badFile);

    return filename;
}

void read()
{
    ifstream in(file());

    string word;

    stringstream line;
    string row;

    int lineNumber = 0;

    while (getline(in, row))
    {

        lineNumber++;
        line.str(row);
        while (line >> word)
        {
            if (word.find("www.") != string::npos || word.find("http://") != string::npos || word.find("https://") != string::npos)
                links.push_back(word);
            else
            {
                word.erase(find_if(word.begin(), word.end(), [](char c)
                                   { return !isalpha(c); }),
                           word.end());
                if (!word.empty())
                {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    words[word].push_back(lineNumber);
                }
            }
        }

        line.clear();
    }

    in.close();
}

void write()
{
    ofstream out("rezultatai.txt");

    if (!out.good())
    {
        cout << "Nepavyko sukurti rezultatai.txt failo." << endl;
        return;
    }

    out << filename << endl
        << endl;

    out << "NUORODOS (" << links.size() << ")" << endl;
    for (auto i : links)
        out << i << endl;

    out << endl;

    out << "PASIKARTOJANTYS ŽODŽIAI (" << words.size() << ")" << endl;
    if (!words.empty())
    {
        out << left << setw(20) << "Žodis" << left << setw(10) << "| Kiekis"
            << "| Eilutėse" << endl;
        out << "--------------------------------------------------------------" << endl;
        for (auto i : words)
        {
            if (i.second.size() > 1)
            {
                out << left << setw(20) << i.first << left << setw(10) << i.second.size();
                for (int j = 0; j < i.second.size(); j++)
                {
                    if (j % 10 == 0 && j != 0)
                        out << endl
                            << setw(30) << "";
                    out << setw(2) << i.second.at(j) << " ";
                }

                out << endl;
                out << "--------------------------------------------------------------" << endl;
            }
        }
    }

    out.close();
}

int main()
{
    read();
    write();
    cout << "Apdorota sėkmingai. Rezultatus rasite rezultatai.txt faile" << endl;
    return 0;
}