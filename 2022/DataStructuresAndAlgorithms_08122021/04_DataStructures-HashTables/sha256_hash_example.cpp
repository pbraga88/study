/*
IMPORTANT NOTE:
TO COMPILE THIS PROGRAM. USE THE FOLLOW:
g++ -I/usr/include/openssl/ sha256_hash_example.cpp -lcrypto
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#define SHA256_DIGEST_LENGTH 32

std::string sha256(const std::string str){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
    }
    return ss.str();
}

int main(){
    std::string var {"Some nonsense phrase!"};
    std::string sha256_hashed_string;
    
    sha256_hashed_string = sha256(var);
    std::cout<<"The string: '"<<var<<"' unique hash256 is:"<<std::endl;
    std::cout<<sha256_hashed_string<<std::endl;

}