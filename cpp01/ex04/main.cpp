#include <string>
#include <fstream>
#include <iostream>


int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "ファイルを開けませんでした" << std::endl;
		return 1;
	}
	std::string file_name = av[1];
	std::ofstream ofs(file_name + ".replace");

	std::string line;
	std::string	sub = av[2];
	std::string	rep = av[3];
	std::size_t	sub_len = sub.length();
	
	while (std::getline(ifs, line))
	{
		std::size_t	pos = line.find(sub);
		while (pos != std::string::npos)
		{
			line.erase(pos, sub_len);
			line.insert(pos, rep);
			pos = line.find(sub);
		}
		ofs << line << std::endl;
	}
}



// using namespace std;
// int main(void)
// {
// 	string s = "myname is myname and yourname is myname";
// 	string sub = "myname";
// 	string rep = "ioio";

// 	// cout << s.find("myname") << endl;
// 	// int i = s.find("myname");
// 	// s.erase(i, sub.length());
// 	// cout << s.insert(i, rep) << endl;
// 	// int j = s.find("myname");
// 	// s.erase(j ,sub.length());
// 	// cout << s.insert(j, rep) << endl;
	
// 	std::size_t pos = s.find(sub);
// 	std::size_t sub_len = sub.length();
// 	while (pos != std::string::npos)
// 	{
// 		s.erase(pos, sub_len);
// 		s.insert(pos, rep);
// 		pos = s.find(sub);
// 	}
// 	cout << s << endl;
// }

