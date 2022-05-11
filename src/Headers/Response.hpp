//
// Created by NelsonWork on 11.05.2022.
//

#ifndef POA_L3_RESPONSE_HPP
#define POA_L3_RESPONSE_HPP


#include <string>

/**
 * Represent a Response
 * @version 1.0
 * @date 11.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class Response {
private:
    const bool allowed;
    const std::string reason;
public:
    Response(bool allowed, const std::string& reason);
    explicit Response(bool allowed);
    bool isAllowed() const;
    std::string getReason() const;
};


#endif //POA_L3_RESPONSE_HPP
