#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class ConstStrBlobPtr;

class StrBlob {
friend class StrBlobPtr;
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il):
        data(std::make_shared<std::vector<std::string>>(il)) {}
public:
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;
    size_type size() const { return data->size(); }
    void push_back(const std::string& s) { data->push_back(s); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }
    std::string front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    std::string back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const std::string front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }
private:
    void check(std::size_t i, const std::string& msg) const {
        if (i > data->size()) { throw std::out_of_range(msg); }
    }
private:
    std::shared_ptr<std::vector<std::string>> data;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr();
    ConstStrBlobPtr(const StrBlob&, std::size_t sz = 0);
    bool operator!=(ConstStrBlobPtr& p) const {
        return curr != p.curr;
    }
public:
    std::string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr() {
        check(curr, "increment past end");
        ++curr;
        return *this;
    }
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const {
        auto ret = wptr.lock();
        if (!ret) { throw std::runtime_error("unbound StrBlobPtr"); }
        if (i > ret->size()) { throw std::out_of_range(msg); }
        return ret;
    }
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};
