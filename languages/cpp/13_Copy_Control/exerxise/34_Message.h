/* Write the Message class as described in this section. */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message {
friend class Folder;
friend void swap(Message &lhs, Message &rhs);
public:
  Message(const std::string str = "") : content(str) {}
  Message(Message &rhs);
  Message &operator=(Message &rhs);
  ~Message();
public:
  void swap(Message &rhs);
  void save(Folder&);
  void remove(Folder&);
private:
  void addToFolders(Message& rhs);
  void removeFromFolders();
private:
  std::string content;
  std::set<Folder *> folders;
};

class Folder {
public:
  void addMsg(Message& msg);
  void rmMsg(Message& msg);
private:
  std::set<Message *> msgs;
};

void swap(Message &lhs, Message &rhs);

inline void swap(Message &lhs, Message &rhs) {
  lhs.swap(rhs);
}

#endif /* MESSAGE_H */
