#include <deque>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class textgen {
public:
    typedef std::deque<std::string> prefix;
    textgen(std::ifstream& file);
    textgen(const std::string& src);
    std::string generate_text();
    std::string generate_from(const prefix& first);
    std::map<prefix, std::vector<std::string>> get_prefixs();
private:    
    const int NPREF=2;
    const int MAXGEN=1000;
    std::map<prefix, std::vector<std::string>> statetab;
};