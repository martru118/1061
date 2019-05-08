class A {};

void setup_board(char board[][7], int fill[]);

void print_board(char board[][7]);

bool place_disk(char board[][7], int c, char d, int fill[]);

void save_state_as_text(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int turn);

void save_state_as_binary(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int turn);

bool load_state_from_text(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int& turn);

bool load_state_from_binary(std::string filename, char board[][7], int fill[], std::string players[], char disks[], int& turn);
