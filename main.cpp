#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  cout << "Welcome to DeathDB!\n\n";
  
  // Israel-Palestine ASCII art
  
  cout << "########%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(%&@@@@@@@@&%###%%%%#%%&&@@@@@@@@@&\n";
  cout << "(##########@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&##&@@@@@@@@@&%###%%%%%%&&@@@@@@@@@@@&\n";
  cout << "%%%%##########@@@@@@@@@@@@@@@@@@@@@@@@@@&((####(/**,..            ...........    \n";
  cout << "&&&&&&&&&&&%%&&&&@@@@@@@@@@@@@@@@@@@@@@&%&&&%##(/*,,.       &    ...........     \n";
  cout << "&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@&&%%#(/*,.       %&&   .........       \n";
  cout << "&&&&&&&&&&&&&&&&&&&&%%%             ...,,,*****,,..      %%  .@%  .. ...         \n";
  cout << "&&&&&&&&&&&&&&&&&&&&%%%%%%     ........,,,,***,,. #((####%##/*,@@..,,&&          \n";
  cout << "#%&&&&&&&&&%%%%%%%%%%%%&&&&&&..........,,,,,,,,.   #( (#        (&,%&.           \n";
  cout << "&&%###%&&&&&&&&%%%%%%%%%%&&&&&&&........,,...        (#           &&             \n";
  cout << "&&&&&&&%####%%%&%%%%%###%%%%&*......               ## ##        *#.#%            \n";
  cout << "%%&&&&&&&&&&&%%###########               ........ %%   ,#*     #%   .%&        . \n";
  cout << "####%%&&&&&&&&&&&&&&%%%                ..........        %%   &#         ....... \n";
  cout << "&&%######%&&&&&&&&&&&%%%%%##(//****/////**,,..            &@@@ ................. \n";
  cout << "&&&&&%%#####%%%&&&%%%%%%%%%%%%%%%%%#####((((///**,,,........@................... \n";
  cout << "&&&&&&&&&%####%########%%%%%%%%%%%%%%%%%%%##((//**,,,.................           \n";
  cout << "#%%%%&&&&&&%##/**/(###%%%########%%%%%%%&&&&&&@@@@@@@@@@@@@@@@&&&%%%############ \n\n";

  cout << "Which region do want to see the death count of?\n1. Israel\n2. Gaza\n3. West Bank:\n";

  int region;
  string date;

  cin >> region;

  cout << "\n\nEnter the date you want to see the death count of (YYYY-MM-DD): ";

  cin >> date;

  // reading from SQL filed
  
  string db_line;
  string db_text;

  cout << "\n\n";

  if (region == 1) {
    ifstream file("israel.sql");
    while (getline(file, db_line)) {
      db_text += db_line + "\n";
    }

    file.close();

    db_text += "where date_of_count = \'"+ date + "\';"; // adding SQL syntax to output death count for a specific date

    ofstream outfile;
    outfile.open("israel2.sql");
    outfile << db_text;
    outfile.close();

    int cmd;
    cmd = system("sqlite3 --init israel2.sql");

    // Running shell command to execute SQL file
  }

  if (region == 2) {
    ifstream file("gaza.sql");
    while (getline(file, db_line)) {
      db_text += db_line + "\n";
    }

    file.close();

    db_text += "where date_of_count = \'"+ date + "\';";

    ofstream outfile;
    outfile.open("gaza2.sql");
    outfile << db_text;
    outfile.close();

    int cmd;
    cmd = system("sqlite3 --init gaza2.sql");
  }

  if (region == 3) {
    ifstream file("west_bank.sql");
    while (getline(file, db_line)) {
      db_text += db_line + "\n";
    }

    file.close();

    db_text += "where date_of_count = \'"+ date + "\';";

    ofstream outfile;
    outfile.open("west_bank2.sql");
    outfile << db_text;
    outfile.close();

    int cmd;
    cmd = system("sqlite3 --init west_bank2.sql");
  }
  
}