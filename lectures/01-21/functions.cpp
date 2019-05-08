#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void setup_board(char board[][7], int fill[])
{
    for (int i=0; i<7; ++i) fill[i] = 0;

    // _ -> empty, r -> red, y -> yellow
    for (int r=0; r<6; ++r) {
        for (int c=0; c<7; ++c) {
            board[r][c] = '_';
        }
    }
}

void print_board(char board[][7])
{
    cout << endl;
    for (int r=5; r>=0; --r) {
        for (int c=0; c<7; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool place_disk(char board[][7], int c, char d, int fill[])
{
    if (fill[c] > 5) return false;

    board[fill[c]][c] = d;
    fill[c] = fill[c] + 1;
    return true;
}

void save_state_as_text(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int turn)
{
  ofstream f(filename);
  if (!f.is_open()) {
    cerr << "Error opening file " << filename << " for saving." << endl;
    return;
  }

  for (int i=0; i<2; ++i) {
    f << players[i] << " " << disks[i] << endl;
  }
  f << turn << endl;

  for (int r=0; r<6; ++r) {
    for (int c=0; c<7; ++c) {
      f << board[r][c] << " ";
    }
    f << endl;
  }
  
  for (int c=0; c<7; ++c) {
    f << fill[c] << " ";
  }
  f << endl;

  if (f.fail()) {
    cerr << "Error saving information to file." << endl;
  }
  
  f.close();
}

void save_state_as_binary(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int turn)
{
  ofstream f(filename, ios::binary);

  for (int i=0; i<2; ++i) {
    int len = players[i].size();
    //cout << len << endl;
    f.write((const char*)&len, sizeof(int));
    f.write(players[i].c_str(), sizeof(char)*len);
    f.write((const char*)&disks[i], sizeof(char));
  }
  f.write((const char*) &turn, sizeof(int));
  f.write((const char*) board, sizeof(char)*6*7);
  f.write((const char*) fill, sizeof(int)*7);
  
  f.close();
}

bool load_state_from_text(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int& turn)
{
  ifstream f(filename);
  if (!f.is_open()) {
    cerr << "Error opening file " << filename << " for saving." << endl;
    return false;
  }

  for (int i=0; i<2; ++i) {
    f >> players[i] >> disks[i];
  }
  f >> turn;

  for (int r=0; r<6; ++r) {
    for (int c=0; c<7; ++c) {
      f >> board[r][c];
    }
  }
  
  for (int c=0; c<7; ++c) {
    f >> fill[c];
  }

  if (f.fail()) {
    cerr << "Error reading information from file." << endl;
    return false;
  }
  
  f.close();
  
  return true;
}

bool load_state_from_binary(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int& turn)
{
  ifstream f(filename, ios::binary);
  if (!f.is_open()) {
    cerr << "Error opening file " << filename << " for saving." << endl;
    return false;
  }

  for (int i=0; i<2; ++i) {
    int nbytes;
    f.read((char*)&nbytes, sizeof(int));
    cout << nbytes << endl;

    char name[100];
    f.read(name, nbytes); name[nbytes]='\0';
    players[i] = string(name);
    cout << players[i] << endl;

    f.read((char*)&disks[i], 1);
    cout << disks[i] << endl;
  }

  f.read((char*) &turn, sizeof(int));
  f.read((char*) board, 6*7);
  f.read((char*) fill, sizeof(int)*7);  

  if (f.fail()) {
    cerr << "Error reading information from file." << endl;
    return false;
  }
  
  f.close();
  
  return true;
}
