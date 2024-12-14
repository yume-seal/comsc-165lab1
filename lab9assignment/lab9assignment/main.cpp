/*
* Name: Madeeha Adam
* 
*
*/

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;

struct Vocaloid {
    string sayThis;
    Vocaloid* yes;
    Vocaloid* no;
};

void serialiseDown(ofstream& fout, Vocaloid* navigator)
{
    if(navigator == nullptr)
    {
        fout << "EOF\n";
    }
    else
    {
        fout << navigator->sayThis << "\n";
        serialiseDown(fout, navigator->yes);
        serialiseDown(fout, navigator->no);
    }
}

void deallocate(Vocaloid* navigator)
{
    if(navigator == 0)
    {
        return;
    }
    deallocate(navigator->yes);
    deallocate(navigator->no);
    delete navigator;
}
int main(int argc, const char * argv[])
{
    
    Vocaloid* miku = new Vocaloid {"It's Hatsune Miku"};
    Vocaloid* rin = new Vocaloid {"It's Kagamine Rin"};
    Vocaloid* kaito = new Vocaloid {"It's Kaito"};
    Vocaloid* len = new Vocaloid {"It's Kagamine Len"};
    Vocaloid* meiko = new Vocaloid {"It's Meiko"};
    Vocaloid* luka = new Vocaloid {"It's Megurine Luka"};
    Vocaloid* gakupo = new Vocaloid {"It's Gakupo Kamui"};
    Vocaloid* oliver = new Vocaloid {"It's Oliver"};
    Vocaloid* ml = new Vocaloid {"Does your vocaloid have pink hair?", luka, miku};
    Vocaloid* kr = new Vocaloid {"Does your vocaloid have brown hair?", meiko, rin};
    Vocaloid* ol = new Vocaloid {"Does your vocaloid have a bandage over his eye?", oliver, len};
    Vocaloid* gk = new Vocaloid {"Does your vocaloid like ice cream?", kaito, gakupo};
    Vocaloid* mrkl = new Vocaloid {"Does your vocaloid have long hair?", ml, kr};
    Vocaloid* gkol = new Vocaloid {"Is your vocaloid blond?", ol, gk};
    Vocaloid* firstQuestion = new Vocaloid {"Is your vocaloid female?", mrkl, gkol};
    Vocaloid* top = firstQuestion; //
    string input;
    cout << "Think of a vocaloid, and I'll identify who it is." << endl;
    Vocaloid* navigator = top;
    
    while(true)
    {
        cout << "\n" << navigator->sayThis;
        if(navigator->yes == 0 && navigator->no == 0)
        {
            break;
        }
        cout << "[y/n]? ";
        cin >> input;
        if(input == "Y" || input == "y")
        {
            navigator = navigator->yes;
        }
        else if(input == "N" || input == "n")
        {
            navigator = navigator->no;
        }
        else
        {
            cout << "\nInvalid input, please try again." << endl;
        }
    }
    cout << "\n";
    ofstream fout;
    fout.open("ai.txt");
    serialiseDown(fout, top);
    fout.close();
    return 0;
}
