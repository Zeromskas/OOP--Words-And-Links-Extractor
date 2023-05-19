#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <unordered_set>

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
using std::unordered_set;
using std::ispunct;

unordered_set<string> links;
map<string, vector<int>> words;
string filename;

string file()
{
    cout <<endl<< "--------------------------------------------------------------" << endl;
    cout<< "Dabartinėje direktorijoje egzistojantys failai:"<<endl;
    cout<<"---"<<endl;
    system("ls *.txt");
    cout << "---" << endl;
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

    system("clear");
    cout<<filename<<endl;

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
            {
                if (ispunct(word.back()))
                {
                    word.pop_back();
                }
                links.insert(word);
            }
                
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

    out << "PASIKARTOJANTYS ŽODŽIAI" << endl;
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

    cout<<"--------------------------------------------------------------"<<endl;
    cout << "Apdorota sėkmingai" << endl;
    cout << "Rasta " << links.size() << " nuorodų ir " << words.size() << " unikalių žodžių" << endl;
    cout << "Detalius rezultatus rasite rezultatai.txt faile" << endl;
    cout << "--------------------------------------------------------------" << endl;
    return 0;
}