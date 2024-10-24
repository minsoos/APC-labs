///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS {
size_t SocialNetwork::CUserIndex(const std::string &name,
                                 const std::string &surname) const {
  size_t i;

  User u(name, surname);

  bool found = false;

  for (i = 0; i < users.size() && !found; ++i)
    if (users[i] == u)
      found = true;

  if (found)
    return --i;
  else
    return users.size();
}

void SocialNetwork::AddUser(const std::string &name,
                            const std::string &surname) {

  /* YOUR CODE GOES HERE */

}

const std::vector<User> SocialNetwork::CGetUsers() const {
  return users;
}

const std::vector<User> SocialNetwork::CGetFriends(const User &user) const {

  /* YOUR CODE GOES HERE */

}

const std::vector<User> SocialNetwork::CGetFriends(const std::string &name,
                                                   const std::string &surname) const {
  std::vector<User> ret{};

  /* YOUR CODE GOES HERE */

  return ret;

}

void SocialNetwork::AddFriendship(const std::string &first_name,
                                  const std::string &first_surname,
                                  const std::string &second_name,
                                  const std::string &second_surname) {

  /* YOUR CODE GOES HERE */

}

}
