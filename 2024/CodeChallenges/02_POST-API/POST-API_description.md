https://chat.openai.com/share/10b36ee3-a4ec-4337-8a52-44dd1dfed7ed

# POST API
You are required to write a POST API endpoint that is responsible for creating users and saving them into mocked-up database.  
## Requirements  
In order to satisfy the task's requirements you must implement a POST /users API endpoint which will:
1. accept std::string route and payload in JSON format,
2. accept two properties in the payload: name and age;
3. return status code 400 if the route is incorrect (different from /users);
4. return status code 488 if either name or age is missing;
5. return status code 400 if either age is not a number or name is not a string;
6. return status code 400 if name is longer than 32 characters;
7. return status code 400 if age is less than 16;
8. create a User object using validated data;
9. call the save function (provided in the header file) if none of the above conditions fail, which will save the User object in the mocked-up database and return a 201 status code.  

## Assumptions
• You should avoid direct calls to the database.  
• The save method is a helper read-only function that accepts a User object as a parameter.  
• You can assume that the save function never throws any error.  
• You do not need any knowledge of how the save function works. You only need to use it at the end of task implementation to save objects in the database.  
• age should be of type number; age of any other type should result in status code 480.  
• name should be of type string; name of any other type should result in status code 488.  
## Hints
• JSON handling relies on the RapidJSON library.  
• For JSON handling you'll have to use the RapidJSON API:  
• Document::HasMember(const char* json_key) checks whether the JSON member specified by json_key exists in the Document object;  
• Document::operator[](const char* json_key) reads the JSON member under json_key and returns its value as a value type;  
• you can test whether the value variable is a string or a number by calling Value::IsString() or Value::IsNumber() respectively;  
• you can fetch proper data for the C++ primitive type by calling helper methods such as Value::GetString() or Value::GetInt(), ), which will return const char* and int respectively.  

### Available packages/libraries:
C++17, RapidJSON

### post_api.h:
```cpp
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
```