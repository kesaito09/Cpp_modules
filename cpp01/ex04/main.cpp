#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string sed_content(std::ifstream& ifs, const std::string& sub,
                        const std::string& rep) {
  std::size_t sub_len = sub.length();
  std::size_t rep_len = rep.length();
  std::stringstream ss;
  ss << ifs.rdbuf();
  std::string content = ss.str();
  std::size_t pos = content.find(sub);
  while (pos != std::string::npos) {
    content.erase(pos, sub_len);
    content.insert(pos, rep);
    pos = content.find(sub, pos + rep_len);
  }
  return content;
}

// streamはコピー禁止だから、参照を渡す。
bool openfile(const std::string& name, std::ifstream& ifs, std::ofstream& ofs) {
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
  ofs << sed_content(ifs, sub, rep);
  return 0;
}
