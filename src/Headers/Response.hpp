#ifndef POA_L3_RESPONSE_HPP
#define POA_L3_RESPONSE_HPP

#include <string>

/**
 * Represent a Response
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Response {
private:
    const bool allowed;
    const std::string reason;

public:
   /**
    * Constructor
    * @param allowed
    * @param reason
    */
    Response(bool allowed, const std::string& reason);

    /**
     * Constructor
     * @param allowed
     */
    explicit Response(bool allowed);

    /**
     * Method to get boolean
     * @return bool
     */
    bool isAllowed() const;

    /**
     * Method to get message
     * @return message of error if there is one
     */
    std::string getReason() const;
};

#endif //POA_L3_RESPONSE_HPP
