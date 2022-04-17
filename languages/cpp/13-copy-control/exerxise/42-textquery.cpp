#include "42_TextQuery.h"
#include <cstddef>

static std::string make_plural(std::size_t ctr, const std::string &word,
                               const std::string &ending) {
  return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << make_plural(qr.lines->size(), "time", "s") << std::endl;

  for (auto &num : *qr.lines) {
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num)
       << std::endl;
  }

  return os;
}

TextQuery::TextQuery(std::ifstream &infile)
    : file(new StrVec) {
  for (std::string text; std::getline(infile, text); /* empty */) {
    file->push_back(text); // remember this line of text

    int n = file->size() - 1; // the current line number
    std::istringstream istrm(text);
    for (std::string word; istrm >> word;) {
      auto &lines = wm[word];
      if (!lines) {
        lines.reset(new std::set<size_t>);
      }
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const std::string &sought) const {
  static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>);
  auto loc = wm.find(sought);
  if (loc == wm.end()) {
    return QueryResult(sought, nodata, file);
  } else {
    return QueryResult(sought, loc->second, file);
  }
}
