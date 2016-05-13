#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool ends_with(string value, string ending) {
  if (ending.size() > value.size()) {
    return false;
  }
  return equal(ending.rbegin(), ending.rend(), value.rbegin());
}

vector<string> load_file(string path) {
  vector<string> vs;
  fstream fs (path.c_str(), fstream::in);

  while (!fs.eof()) {
    string current;
    getline(fs, current);

    vs.push_back(current);
  }

  fs.close();
  return vs;
}

vector<string> load_files() {
  vector<string> vs;
  fstream fs ("concepts", fstream::in);
  if (fs.fail()) {
    return vs;
  }

  while (!fs.eof()) {
    string current;
    getline(fs, current);
    vs.push_back(current);
  }
  fs.close();
  return vs;
}

int main(int argc, char** argv) {  

  vector<string> files = load_files();

  auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  srand(now);

  cout << "\x1B[0;32mIdea\x1B[0m ";

  for (int index = 1; index < argc; index++) {
    string concept (argv[index]);

    bool found = false;
    for (auto it = files.begin(); it != files.end(); it++) {
      if (ends_with(*it, concept)) {
        vector<string> things = load_file(*it);
        int rindex = nearbyint(((float)rand() / (float)RAND_MAX) * (things.size() - 1));
        cout << things[rindex];
        found = true;
        break;
      }
    }

    if (!found) {
      cout << concept;
    } else {
      cout << " ";
    }
  }

  cout << "\n";

  return 0;

}
