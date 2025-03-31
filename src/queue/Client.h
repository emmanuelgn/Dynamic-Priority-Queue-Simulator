// Copyright [2025] Emmanuel Notargiacomo
// Client.h

#ifndef SRC_QUEUE_CLIENT_H_
#define SRC_QUEUE_CLIENT_H_

#include <string>

class Client {
 public:
    Client();
    explicit Client(const std::string &name);

    void set_name(const std::string &name);
    const std::string &get_name() const;

 private:
    std::string name_;
};

#endif  // SRC_QUEUE_CLIENT_H_
