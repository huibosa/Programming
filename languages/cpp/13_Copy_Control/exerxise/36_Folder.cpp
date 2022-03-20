/* Write the Message class as described in this section. */

#include "36_Folder.h"
#include <utility>

Message::Message(Message &rhs) : content(rhs.content), folders(rhs.folders) {
  addToFolders(rhs);
}

Message& Message::operator=(Message &rhs) {
  removeFromFolders();
  content = rhs.content;
  folders = rhs.folders;
  addToFolders(*this);

  return *this;
}

Message::~Message() {
  removeFromFolders();
}

/////////////////////////////////////////////////////////////////////////////////

void Message::swap(Message& rhs) {
  using std::swap;
  
  this->removeFromFolders();
  rhs.removeFromFolders();

  swap(content, rhs.content);
  swap(folders, rhs.folders);

  this->addToFolders(*this);
  rhs.addToFolders(rhs);
}

void Message::save(Folder& f) {
  folders.insert(&f);
  f.addMsg(*this);
}

void Message::remove(Folder& f) {
  folders.erase(&f);
  f.rmMsg(*this);
}

void Message::addToFolders(Message &rhs) {
  for (auto f : rhs.folders) {
    f->addMsg(*this);
  }
}

void Message::removeFromFolders() {
  for (auto f : this->folders) {
    f->rmMsg(*this);
  }
}

//////////////////////////////////////////////////////////////////////////////////

Folder::Folder(Folder& rhs): msgs(rhs.msgs) {
  addToMsgs(*this);
}

Folder::~Folder() {
  removeFromMsgs();
}

Folder& Folder::operator=(Folder &rhs) {
  removeFromMsgs();
  msgs = rhs.msgs;
  addToMsgs(rhs);

  return *this;
}

void Folder::swap(Folder& rhs) {
  using std::swap;
  
  this->removeFromMsgs();
  rhs.removeFromMsgs();

  swap(msgs, rhs.msgs);

  this->addToMsgs(*this);
  rhs.addToMsgs(rhs);
}

void Folder::addToMsgs(Folder& f) {
  for (auto m : f.msgs) {
    m->folders.insert(this);
  }
}

void Folder::removeFromMsgs() {
  for (auto m : msgs) {
    m->folders.erase(this);
  }
}

void Folder::addMsg(Message &msg) {
  msgs.insert(&msg);
  msg.folders.insert(this);
}

void Folder::rmMsg(Message &msg) {
  msgs.erase(&msg);
  msg.folders.erase(this);
}
