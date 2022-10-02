#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

vector<fs::directory_entry> getEntry(string dir) {
  vector<fs::directory_entry> entry_dirs;
  
  for (const auto &entry : fs::directory_iterator(dir)) {
    entry_dirs.push_back(entry);
  }
    
  return entry_dirs;
}

void loop(string path, int s) {
  vector<fs::directory_entry> list;
  list = getEntry(path);

  for (const auto &i : list) {
    for (int i = 0; i<s; i++) 
      cout << " ";

    cout << i.path().filename();



    if (i.is_directory()) {
      cout << ":" << endl;
      loop(i.path(), s+2);
    } 
    else {
      cout << endl;
    }

  }
}

int main(int argc, char *argv[]) { 
 

  loop(argv[1], 0);

  return 0;
}
