/* Add members to the Message class to insert or remove a */
/* given Folder* into folders. These members are analogous to Folder’s */
/* addMsg and remMsg operations. */

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
  void addFolder(Folder* f) { folders.insert(f); }
  void rmFolder(Folder* f) { folders.erase(f); }
private:
  std::string content;
  std::set<Folder *> folders;
};

void swap(Message &lhs, Message &rhs);


class Folder {
friend void swap(Folder& lhs, Folder& rhs);
friend class Message;
public:
  Folder() = default;
  Folder(Folder& rhs);
  Folder& operator=(Folder& rhs);
  ~Folder();
  void swap(Folder& rhs);
public:
  void addMsg(Message* msg) { msgs.insert(msg); }
  void rmMsg(Message* msg) { msgs.insert(msg); }
private:
  void addToMsgs(Folder& rhs);
  void removeFromMsgs();
private:
  std::set<Message *> msgs;
};

void swap(Folder& lhs, Folder& rhs);


#endif /* MESSAGE_H */
