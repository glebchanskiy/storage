#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

using namespace std;

vector<fs::directory_entry> getEntry(string dir) {
  vector<fs::directory_entry> entry_dirs;
  
  for (const auto &entry : fs::directory_iterator(dir)) {
    entry_dirs.push_back(entry);
  }
    
  return entry_dirs;
}

bool search(string path) {

  return 0;
}

int main(int argc, char *argv[]) { 

  char* line = "lol";
  vector<fs::directory_entry> file_list = getEntry(argv[1]);
  
  for (const auto &entry : file_list) {
    if (!entry.is_directory()) {
      pid_t pid = fork();
      if (pid == 0) {
        cout << "pid: " << getpid() << ", ";
        cout << "filename: " << entry.path().filename() << ", ";

        ifstream file(entry.path(), fstream::in | ios::binary);

        cout << "bytes viewed: " << ", ";
        cout << "search status: " << search(entry.path()) << endl;
        return 0;
      }
    }
  }
  // pid_t wait(-1);
  return 0;
}
