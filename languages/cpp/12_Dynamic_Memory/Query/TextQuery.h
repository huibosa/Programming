#pragma once

#include <cstddef>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <string>
#include <sstream>

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                               std::shared_ptr<std::vector<std::string>> f):
                sought(s), lines(p), file(f) {  }
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
public:
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
