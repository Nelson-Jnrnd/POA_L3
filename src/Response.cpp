#include "Headers/Response.hpp"

Response::Response(bool allowed, const std::string &reason) : allowed(allowed), reason(reason) {}

bool Response::isAllowed() const {
    return allowed;
}

std::string Response::getReason() const {
    return reason;
}

Response::Response(bool allowed) : Response(allowed, "") {}
