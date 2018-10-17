#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <exception>

class base_exception : public std::exception {
protected:
    std::string message;

public:
    explicit base_exception() = default;

    explicit base_exception(const char* message) {
        this->message = message;
    }

    explicit base_exception(std::string& message) {
        this->message = message;
    }
};

class bad_alloc_exception : public base_exception {
public:
    explicit bad_alloc_exception() = default;

    explicit bad_alloc_exception(const char* message)
            : base_exception(message) {
    }

    explicit bad_alloc_exception(std::string& message)
            : base_exception(message) {
    }

    virtual const char* what() const noexcept {
        return message.empty() ? "Error! \nBad allocation : " : message.c_str();
    }
};

class common_exception : public base_exception {
public:
    explicit common_exception() = default;

    explicit common_exception(const char* message)
            : base_exception(message) {
    }

    explicit common_exception(std::string& message)
            : base_exception(message) {
    }

    virtual const char* what() const noexcept {
        return message.empty() ? "Error! \nInfo : " : message.c_str();
    }
};

class out_of_range_exception : public base_exception {
public:
    explicit out_of_range_exception() = default;

    explicit out_of_range_exception(const char* message)
            : base_exception(message) {
    }

    explicit out_of_range_exception(std::string& message)
            : base_exception(message) {
    }

    virtual const char* what() const noexcept {
        return message.empty() ? "Error! \nOut of range : " : message.c_str();
    }
};

#endif // EXCEPTIONS_H
