// Copyright [2025] Emmanuel Notargiacomo
// Client.cpp

#include "Client.h"

Client::Client() : name_("") {}

Client::Client(const std::string &name) : name_(name) {}

void Client::set_name(const std::string &name) {
    name_ = name;
}

const std::string &Client::get_name() const {
    return name_;
}
