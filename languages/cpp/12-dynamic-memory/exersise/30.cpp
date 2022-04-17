#include "30.h"
#include <iterator>
#include <memory>
#include <set>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

TextQuery::TextQuery(std::ifstream& ifs): input(new std::vector<std::string>) {
    LineNo lineNo{ 0 };
    for (std::string line; std::getline(ifs, line); ++lineNo) {
        input->push_back(line);
        std::istringstream line_stream(line);
        for (std::string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            auto& nos = result[word];
            if (!nos) {
                nos.reset(new std::set<LineNo>);
            }
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const std::string& str) const {
    static std::shared_ptr<std::set<LineNo>> noData(new std::set<LineNo>);
    auto loc = result.find(str);
    if (loc == result.end()) {
        return QueryResult(str, noData, input);
    }
    else {
        return QueryResult(str, loc->second, input);
    }
}

std::ostream& print(std::ostream &out, const QueryResult& qr) {
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i+1 << ") " << qr.input->at(i) << std::endl;
    return out;
}
