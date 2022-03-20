#pragma once

#include "42_StrVec.h"
#include <cstddef>
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);
public:
  QueryResult(std::string s, std::shared_ptr<std::set<size_t>> p,
              std::shared_ptr<StrVec> f)
      : sought(s), lines(p), file(f) {}

private:
  std::string sought;
  std::shared_ptr<std::set<size_t>> lines;
  std::shared_ptr<StrVec> file;
};

class TextQuery {
public:
  TextQuery(std::ifstream &);

public:
  QueryResult query(const std::string &) const;

private:
  std::shared_ptr<StrVec> file;
  std::map<std::string, std::shared_ptr<std::set<size_t>>> wm;
};
