#include <fstream>
#include <iostream>
#include <string>

bool read_content(std::ifstream& ifs, std::string& result) {
  std::string line;
  std::string content;
  while (std::getline(ifs, line)) {
    content += line;
    if (!ifs.eof()) content += '\n';
  }
  if (ifs.bad() || !ifs.eof()) return false;
  result = content;
  return true;
}

void sed_content(const std::string& sub, const std::string& rep,
                 std::string& result) {
  std::size_t sub_len = sub.length();
  std::size_t rep_len = rep.length();

  std::size_t pos = result.find(sub);
  while (pos != std::string::npos) {
    result.erase(pos, sub_len);
    result.insert(pos, rep);
    pos = result.find(sub, pos + rep_len);
  }
}

bool openfile(const std::string& name, std::ifstream& ifs, std::ofstream& ofs) {
  //.openはconst char *を受け取るから[string.c_str]で作る。
  ifs.open(name.c_str());
  if (!ifs.is_open()) {
    std::cout << "ファイルを開けませんでした" << std::endl;
    return false;
  }
  ofs.open((name + ".replace").c_str());
  if (!ofs.is_open()) {
    std::cout << "ファイルを開けませんでした" << std::endl;
    return false;
  }
  return true;
}

int main(int ac, char** av) {
  if (ac != 4) return (1);
  std::string sub = av[2];
  std::string rep = av[3];
  if (sub.empty()) {
    std::cout << "sed: first RE may not be empty" << std::endl;
    return 1;
  }
  std::ifstream ifs;
  std::ofstream ofs;
  if (!openfile(av[1], ifs, ofs)) return 1;
  std::string result;
  if (!read_content(ifs, result)) return 1;
  sed_content(sub, rep, result);
  ofs << result;
  if (!ofs) return 1;
  return 0;
}
