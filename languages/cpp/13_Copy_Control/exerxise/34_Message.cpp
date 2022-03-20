/* Write the Message class as described in this section. */

#include "34_Message.h"

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
