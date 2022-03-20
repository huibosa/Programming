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
  void swap(Message &rhs);
public:
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
friend void swap(Folder& lhs, Folder& rhs);
public:
  Folder() = default;
  Folder(Folder& rhs);
  Folder& operator=(Folder& rhs);
  ~Folder();
  void swap(Folder& rhs);
public:
  void addMsg(Message& msg);
  void rmMsg(Message& msg);
private:
  void addToMsgs(Folder& rhs);
  void removeFromMsgs();
private:
  std::set<Message *> msgs;
};


void swap(Folder& lhs, Folder& rhs);
void swap(Message &lhs, Message &rhs);

inline void swap(Message &lhs, Message &rhs) {
  lhs.swap(rhs);
}

inline void swap(Folder &lhs, Folder &rhs) {
  lhs.swap(rhs);
}

#endif /* MESSAGE_H */
