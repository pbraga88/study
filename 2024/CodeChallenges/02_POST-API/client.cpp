// ... (Other includes and the rest of the header file)
#include <iostream>
#include "post_api.h"
#include "rapidjson/document.h"


HttpCode ApiClient::httpPost(const std::string &route, const rapidjson::Document &json) {
    // Requirement 3: Check if the route is correct
    if (route != "users") {
        return BAD_REQUEST;
    }

    // Requirement 4: Check if both name and age are present
    if (!json.HasMember("name") || !json.HasMember("age")) {
        return BAD_REQUEST;
    }

    // Requirement 5: Check if name is a string and age is a number
    const rapidjson::Value &name = json["name"];
    const rapidjson::Value &age = json["age"];

    if (!name.IsString()) {
        return BAD_REQUEST;
    }

    if (!age.IsNumber()) {
        return BAD_REQUEST;
    }

    // Requirement 6: Check if name is longer than 32 characters
    std::string userName = name.GetString();
    if (userName.length() > 32) {
        return BAD_REQUEST;
    }

    // Requirement 7: Check if age is less than 16
    int userAge = age.GetInt();
    if (userAge < 16) {
        return BAD_REQUEST;
    }

    // Requirement 8: Create a User object using validated data
    User newUser{userAge, userName};

    // Requirement 9: Call the save function
    save(newUser);

    // If none of the above conditions fail, return a 201 status code
    return CREATED;
}

int main() {
    std::shared_ptr<MockedDatabase> db;
    

    ApiClient someUser(db);

    return 0;
}