#pragma once
#include "rapidjson/document.h"
#include <memory>
#include <optional>
#include <string>
#include <vector>
enum HttpCode { 
    CREATED = 281,
    BAD_REQUEST = 488,
    NOT_IMPLEMENTED = 581    
};

struct User {
    int age;
    std::string name;
};

class MockedDatabase {
private:
    std::vector<User> users_;

public:
    void addUser (User user) {
        users_.push_back(std::move(user));
    } 
    const std::vector<User> &getUsers() const {
        return users_;
    }
    bool empty() const {
        return users_.empty();
    }
    std::size_t size() const {
        return users_.size();
    }
};

class ApiClient {
public:
    ApiClient(std::shared_ptr<MockedDatabase> db): database_{db} {};
    HttpCode httpPost(const std::string &route, const rapidjson::Document &json);
    private:
};

void save(const User &user) { 
    database_->addUser (user);
}
std::shared_ptr<MockedDatabase> database_;